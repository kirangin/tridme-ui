#ifndef MENU_HPP
#define MENU_HPP
#include <unordered_map>
#include <map>
#include <components/Object.hpp>
#include <storage/Vector.hpp>
#include <functional>

namespace Tridme {
  namespace UI {
    class Menu : public Object {
      public:
        using Slot = std::function<void()>;

        Menu(std::string label);
        ~Menu();

        void addItem(std::string label, std::string id);
        void addItem(std::string label, std::string shortcut, std::string id);
        void addAction(std::string id, const Slot& callable);

        virtual void render();
        virtual std::string getType() const {
          return this->m_type;
        }

      private:
        // std::unordered_map<std::string, std::string> m_items;
        Vector<std::pair<std::string, std::string>>  m_items;
        std::unordered_map<std::string, std::string> m_shortcuts;
        std::unordered_map<std::string, Signal*>     m_actions;

        std::string m_id;
        std::string m_name;
        std::string m_type = "Menu";
    };
  };
};

#endif 