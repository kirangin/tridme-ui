#include <components/TextEdit.hpp>
using namespace Tridme;
using namespace Tridme::UI;

TextEdit::TextEdit() { 
  this->m_name = "Text Edit";
}

TextEdit::TextEdit(std::string name) {
  this->m_name = name;
}

TextEdit::TextEdit(std::string name, std::string content) {
  this->m_name = name;
  this->m_text = content;
}

TextEdit::~TextEdit() {

}

/* Functions */
void TextEdit::setAlignment(TextAlign align) {
  // TODO: implement
  this->m_alignment = align;
}

void TextEdit::setCursorPosition(int position) {
  this->m_cursorPosition = position;
}

void TextEdit::setFrame(bool value) {
  // TODO: implement
  this->m_frame = value;
}

void TextEdit::setMaxLength(int length) {
  this->m_maxLength = length;
}

void TextEdit::setPlaceholderText(std::string text) {
  /*
   * Saat ini ImGui::Multiline tidak support placeholder text. Jadi
   * ini adalah implementasi sementara.
   */
  this->m_placeholderText = text;
  this->m_inputFocused = false;
}

void TextEdit::setReadOnly(bool value) {
  this->m_readOnly = value;
  
  if (this->m_readOnly)
    this->m_flags |= ImGuiInputTextFlags_ReadOnly;
}

void TextEdit::showLabel(bool value) {
  this->m_showLabel = value;
}

std::string TextEdit::getText() const { 
  return this->m_text; 
}

/* For base window */
void TextEdit::render() {
  if (this->m_isVisible) {
    /* Show / Hide Label */
    if (this->m_showLabel && (this->m_name.compare("##") != 0)) 
      ImGui::Text(this->m_name.c_str());

    // get full width
    float width = ImGui::GetContentRegionAvail().x;
    ImGui::InputTextMultilineWithHintmm(this->id.c_str(), &this->m_text, &this->m_placeholderText, ImVec2(width, 0), this->m_flags);

    /* Handle text changed */
    if (ImGui::IsItemEdited()) {
      onTextChanged.emit();
    }
  }
}
