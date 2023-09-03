#ifndef MODALDIALOG_HPP
#define MODALDIALOG_HPP
#include <components/Layout.hpp>
#include <iostream>

namespace Tridme {
  class BaseWindow;

  namespace UI {
    class ModalDialog : public Layout {
      public:
        ModalDialog(BaseWindow& parent);
        // ModalDialog(BaseWindow* window);
        ~ModalDialog();

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
        std::string     m_type = "ModalDialog";
        bool            m_isOpen = false;
        
        std::unordered_map<std::string, Storage::Vector<std::string>> m_componentIds;
    };
  }
}

#endif