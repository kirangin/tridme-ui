#ifndef MENUBAR_HPP
#define MENUBAR_HPP
#include <components/Object.hpp>
#include <components/Menu.hpp>
#include <storage/Vector.hpp>
#include <core/Signal.hpp>

namespace Tridme {
  namespace UI {
    class MenuBar : public Object {
      public:
        MenuBar();
        ~MenuBar();

        void addMenu(Menu* menu);
        int getMenuCount();
        
        virtual void render();
        virtual std::string getType() const {
          return this->m_type;
        }
        
      private:
        Vector<Menu*> m_menus;

        std::string m_id;
        std::string m_name;
        std::string m_type = "MenuBar";
    };
  };
};

#endif 