#include <components/ModalDialog.hpp>
#include <core/BaseWindow.hpp>
using namespace Tridme;
using namespace Tridme::UI;

ModalDialog::ModalDialog(BaseWindow& parent) {
  int id = parent.getDialogCounter() + 1;
  this->m_id = id;

  parent.increaseDialogCounter();
  parent.addModal(this);
}

ModalDialog::~ModalDialog() {

}

void ModalDialog::addComponent(Object* obj) {
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

void ModalDialog::addLayout(Layout* layout) {
  this->m_layouts.pushBack(layout);
}

void ModalDialog::removeComponent(Object* obj) {

}

void ModalDialog::render() {
  if (this->m_isOpen) {
    ImGui::OpenPopup(this->m_id.c_str());
    this->m_isOpen = false;
  }

  ImVec2 center = ImGui::GetMainViewport()->GetCenter();
  ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

  if (ImGui::BeginPopupModal(this->m_id.c_str(), NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
    for (auto layout : m_layouts) {
      layout->render();
    }

    if (ImGui::Button("OK")) {
      ImGui::CloseCurrentPopup();
    }

    ImGui::EndPopup();
  }
}

void ModalDialog::setId(std::string id) {
  this->m_id = id;
}

void ModalDialog::show() {
  this->m_isOpen = true;
}

void ModalDialog::hide() {
  this->m_isOpen = false;
}