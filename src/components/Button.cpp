#include <components/Button.hpp>
using namespace Tridme;
using namespace Tridme::UI;

Button::Button() {
  this->m_label = "Button";
}

Button::Button(std::string text) {
  this->m_label = text; 
}

Button::~Button() {

}

void Button::render() {
  if (m_isVisible) {
    if (ImGui::Button(this->m_label.c_str())) {
      onClick.emit();
    }
  }
}

void Button::setLabel(std::string text) {
  this->m_label = text;
}