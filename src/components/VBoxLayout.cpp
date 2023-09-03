#include <components/VBoxLayout.hpp>
using namespace Tridme;
using namespace Tridme::UI;

VBoxLayout::VBoxLayout() {

}

VBoxLayout::~VBoxLayout() {

}

void VBoxLayout::addComponent(Object* obj) {
  // create object id
  std::string type = obj->getType(); 
  std::string id   = "##" + type + "_";

  if (this->m_componentIds.find(type) != this->m_componentIds.end()) {
    id += "0";
    this->m_componentIds[type].pushBack(id);
  } else {
    id += std::to_string(this->m_componentIds[type].getSize() + 1);
    this->m_componentIds[type].pushBack(id);
  }

  obj->setId(id);

  this->m_components.pushBack(obj);
  m_totalChild += 1;
}

void VBoxLayout::addLayout(Layout* layout) {
  this->m_layouts.pushBack(layout);
}


void VBoxLayout::removeComponent(Object* obj) {
  
}

void VBoxLayout::render() {
  for (auto& obj : this->m_components) {
    ImGui::SetCursorPosY(ImGui::GetCursorPosY());
    obj->render();
  }

  // ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 16);
  
  for (auto& layout : this->m_layouts) {
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 4);
    layout->render();
  }
}

void VBoxLayout::setId(std::string id) {
  this->m_id = id;
}