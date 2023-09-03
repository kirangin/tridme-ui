#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <components/Object.hpp>

namespace Tridme {
  namespace UI {
    class Button : public Object {
      public:
        Button();
        Button(std::string text);
        ~Button();

        void setLabel(std::string label);

        virtual void render();
        virtual std::string getType() const {
          return this->m_type;
        }

        /* Events */
        Signal onClick;
        
      private:
        std::string m_label;
        static bool m_isPressed;

        std::string m_type = "Button"; 
    };
  }
}

#endif