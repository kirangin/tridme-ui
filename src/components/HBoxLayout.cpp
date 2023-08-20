#include <components/HBoxLayout.hpp>
using namespace Tridme;
using namespace Tridme::UI;

HBoxLayout::HBoxLayout() {
  
}

HBoxLayout::~HBoxLayout() {

}

void HBoxLayout::addComponent(Object* obj) {
  

  this->m_components.pushBack(obj);
  // this->m_ids.pushBack(id);
  m_totalChild += 1;
}

void HBoxLayout::removeComponent(Object* obj) {
  
}

void HBoxLayout::render() {
  float width = ImGui::GetContentRegionAvail().x / this->m_totalChild;

  for (auto& obj : this->m_components) {
  // ImGui::PushItemWidth(width);
    obj->render();
    ImGui::SameLine();
  // ImGui::PopItemWidth();
  }


  // if (ImGui::BeginTable("tableLayouts", this->m_totalChild)) {
  //   ImGui::TableNextRow();
  //   for (auto& layout : this->m_layouts) {
  //     ImGui::TableNextColumn();
  //     layout->render();
  //   }

  //   ImGui::EndTable();
  // }
}

void HBoxLayout::setId(std::string id) {
  this->m_id = id;
}
