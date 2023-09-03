#ifndef TEXT_HPP
#define TEXT_HPP
#include <components/Object.hpp>

namespace Tridme {
  namespace UI {
    class Text : public Object {
      public:
        Text();
        Text(std::string text);
        ~Text();

        void setText(std::string text);

        virtual std::string getName() const {
          return this->m_type;
        }
        virtual void render();

      private:
        std::string       m_text;
        std::string m_type = "Text";
    };
  }
}

#endif