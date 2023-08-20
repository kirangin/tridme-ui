#include <components/VBoxLayout.hpp>
using namespace Tridme;
using namespace Tridme::UI;

VBoxLayout::VBoxLayout() {

}

VBoxLayout::~VBoxLayout() {

}

void VBoxLayout::addComponent(Object* obj, std::string id) {
  this->m_components.pushBack(obj);
  this->m_ids.pushBack(id);
  m_totalChild += 1;
}

void VBoxLayout::addLayout(Layout* layout) {
  this->m_layouts.pushBack(layout);
}


void VBoxLayout::removeComponent(Object* obj) {
  
}

void VBoxLayout::render() {
  ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 20);

  for (auto& obj : this->m_components) {
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 20);
    obj->render();
  }

  for (auto& layout : this->m_layouts) {
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 20);
    layout->render();
  }
}