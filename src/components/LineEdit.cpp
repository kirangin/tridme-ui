#include <components/LineEdit.hpp>
using namespace Tridme;
using namespace Tridme::UI;

LineEdit::LineEdit() { 
  this->m_name = "Line Edit";
}

LineEdit::LineEdit(std::string name) {
  this->m_name = name;
}

LineEdit::LineEdit(std::string name, std::string content) {
  this->m_name = name;
  this->m_text = content;
}

LineEdit::~LineEdit() {

}

/* Functions */
void LineEdit::setAlignment(TextAlign align) {
  // TODO: implement
  this->m_alignment = align;
}

void LineEdit::setCursorPosition(int position) {
  this->m_cursorPosition = position;
}

void LineEdit::setFrame(bool value) {
  // TODO: implement
  this->m_frame = value;
}

void LineEdit::setMaxLength(int length) {
  this->m_maxLength = length;
}

void LineEdit::setPlaceholderText(std::string text) {
  this->m_placeholderText = text;
}

void LineEdit::setReadOnly(bool value) {
  this->m_readOnly = value;
  
  if (this->m_readOnly)
    this->m_flags |= ImGuiInputTextFlags_ReadOnly;
}

void LineEdit::showLabel(bool value) {
  this->m_showLabel = value;
}

void LineEdit::hideCharacter(bool value) {
  this->m_hideCharacter = value;

  /* Show / Hide Character untuk password */
  if (this->m_hideCharacter)
    m_flags |= ImGuiInputTextFlags_Password;
}

std::string LineEdit::getText() const { 
  return this->m_text; 
}

/* For base window */
void LineEdit::render() {
  if (this->m_isVisible) {
    /* Show / Hide Label */
    if (this->m_showLabel) 
      ImGui::Text(this->m_name.c_str());

    /* Handle max length */
    if (this->m_maxLength > 0) {
      char* buffer = (char*) this->m_text.c_str();

      if (ImGui::InputTextWithHint(this->id.c_str(), m_placeholderText.c_str(), buffer, this->m_maxLength, m_flags)) {
        onEnterPressed.emit();
      }
    } else {
      /* Default with no max size */
      if (ImGui::InputTextWithHintmm(this->id.c_str(), m_placeholderText.c_str(), &this->m_text, m_flags)) {
        onEnterPressed.emit();
      }
    }

    /* Handle text changed */
    if (ImGui::IsItemEdited()) {
      onTextChanged.emit();
    }
  }
}

void LineEdit::setText(std::string text) {
  this->m_text = text;
}