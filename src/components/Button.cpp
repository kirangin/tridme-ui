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
    float width = ImGui::GetContentRegionAvail().x;

    if (ImGui::Button(this->m_label.c_str(), ImVec2(width, 0))) {
      onClick.emit();
    }
  }
}

void Button::setLabel(std::string text) {
  this->m_label = text;
}