#ifndef LINEEDIT_HPP
#define LINEEDIT_HPP
#include <components/Object.hpp>
#include <misc/cpp/imgui_stdlib.h>

namespace Tridme {
  namespace UI {
    class LineEdit : public Object {
      public:
        LineEdit();
        LineEdit(std::string name);
        LineEdit(std::string name, std::string content);
        ~LineEdit();

        /* Functions */
        void setAlignment(TextAlign align);
        void setCursorPosition(int position);
        void setFrame(bool value);
        void setMaxLength(int length);
        void setPlaceholderText(std::string text);
        void setReadOnly(bool value);
        void setText(std::string text);
        void showLabel(bool value);
        void hideCharacter(bool value);

        std::string getText() const;

        /* Events */
        Signal onTextChanged;
        Signal onEnterPressed;

        /* For base window */
        virtual void render();
        virtual std::string getType() const {
          return this->m_type;
        }
        
      private:
        /* Label Properties */
        TextAlign           m_alignment;
        int                 m_cursorPosition;
        bool                m_frame;
        bool                m_showLabel = true;
        int                 m_maxLength;
        bool                m_readOnly;
        bool                m_hideCharacter;
        std::string         m_text;
        std::string         m_placeholderText;
        std::string         m_id;
        std::string         m_name;
        std::string         m_type = "LineEdit";
        ImGuiInputTextFlags m_flags = ImGuiInputTextFlags_None | ImGuiInputTextFlags_EnterReturnsTrue;
    };
  }
}

#endif