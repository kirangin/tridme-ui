#ifndef VBoxLayout_HPP
#define VBoxLayout_HPP
#include <components/Layout.hpp>
#include <components/Object.hpp>
#include <storage/Vector.hpp>

/*
 * Hbox adalah layout yang item-itemnya berjajar secara horizontal, 
 * seperti kolom.
 */

namespace Tridme {
  namespace UI {
    class VBoxLayout : public Layout {
      public:
        VBoxLayout();
        ~VBoxLayout();

        void addComponent(Object* obj, std::string id);
        void addLayout(Layout* layout);
        void removeComponent(Object* obj);
        void render();
      
        virtual std::string getType() const {
          return this->m_type;
        }
      private:
        Vector<Object*>     m_components;
        Vector<Layout*>     m_layouts;
        int                 m_totalWidth;
        int                 m_totalChild = 0;
        Vector<std::string> m_ids;
        

        std::string     m_type = "VBoxLayout";
    };
  };
};

#endif