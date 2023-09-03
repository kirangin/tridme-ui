#ifndef MODAL_HPP
#define MODAL_HPP
#include <components/Layout.hpp>

namespace Tridme {
  namespace UI {
    class Modal : public Layout {
      public:
        Modal();
        // Modal(BaseWindow* window);
        ~Modal();

        void addComponent(Object* obj);
        void addLayout(Layout* layout);
        void removeComponent(Object* obj);
        void render();
        void setId(std::string id);
        void show();
        void hide();

        virtual std::string getType() const {
          return this->m_type;
        }
      private:
        std::string     m_id;
        Vector<Object*> m_components;
        Vector<Layout*> m_layouts;
        int             m_totalWidth;
        int             m_totalChild = 0;
        std::string     m_type = "Modal";
        bool            m_isOpen = false;
        
        std::unordered_map<std::string, Storage::Vector<std::string>> m_componentIds;
    };
  }
}

#endif