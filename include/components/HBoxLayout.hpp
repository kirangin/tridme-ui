#ifndef HBOXLAYOUT_HPP
#define HBOXLAYOUT_HPP
#include <components/Layout.hpp>
#include <components/Object.hpp>
#include <storage/Vector.hpp>

/*
 * Hbox adalah layout yang item-itemnya berjajar secara horizontal, 
 * seperti kolom.
 */

namespace Tridme {
  namespace UI {
    class HBoxLayout : public Layout {
      public:
        HBoxLayout();
        ~HBoxLayout();

        void addComponent(Object* obj);
        void removeComponent(Object* obj);
        void render();
        void setId(std::string id);

        virtual std::string getType() const {
          return this->m_type;
        }

      private:
        std::string     m_id;
        Vector<Object*> m_components;
        Vector<Layout*> m_layouts;
        int             m_totalChild = 0;
        std::string     m_type = "HBoxLayout";
        
        std::unordered_map<std::string, Storage::Vector<std::string>> m_componentIds;

    };
  };
};

#endif