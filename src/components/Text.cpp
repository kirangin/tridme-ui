#include <components/Text.hpp>
using namespace Tridme;
using namespace Tridme::UI;

Text::Text() {

}

Text::Text(std::string text) {
  this->m_text = text;
}

Text::~Text() {

}

void Text::setText(std::string text) {
  this->m_text = text;
}

void Text::render() {
  if (this->m_isVisible) {
    ImGui::Text(this->m_text.c_str());
  }
}