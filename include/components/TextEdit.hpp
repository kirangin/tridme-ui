#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP
#include <components/Object.hpp>
#include <misc/cpp/imgui_stdlib.h>

namespace Tridme {
  namespace UI {
    class TextEdit : public Object {
      public:
        TextEdit();
        TextEdit(std::string name);
        TextEdit(std::string name, std::string content);
        ~TextEdit();

        /* Methods */
        void setAlignment(TextAlign align);
        void setCursorPosition(int position);
        void setFrame(bool value);
        void setMaxLength(int length);
        void setPlaceholderText(std::string text);
        void setReadOnly(bool value);
        void showLabel(bool value);

        std::string getText() const;

        Signal onTextChanged;

        /* For base window */
        virtual void render();
        virtual std::string getType() const {
          return this->m_type;
        }

      private:
        std::string m_text;
        std::string m_name;

        /* Label Properties */
        TextAlign           m_alignment;
        int                 m_cursorPosition;
        bool                m_frame;
        bool                m_showLabel = true;
        int                 m_maxLength;
        bool                m_readOnly;
        bool                m_inputFocused;
        std::string         m_placeholderText;
        ImGuiInputTextFlags m_flags = ImGuiInputTextFlags_None;
        std::string         m_type = "TextEdit";
    };
  }
}

#endif