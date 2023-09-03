#include <components/HBoxLayout.hpp>
using namespace Tridme;
using namespace Tridme::UI;

HBoxLayout::HBoxLayout() {
  
}

HBoxLayout::~HBoxLayout() {

}

void HBoxLayout::addComponent(Object* obj) {
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

void HBoxLayout::addLayout(Layout* layout) {
  this->m_layouts.pushBack(layout);
  m_totalChild += 1;
}

void HBoxLayout::removeComponent(Object* obj) {
  
}

void HBoxLayout::render() {
  float width = ImGui::GetContentRegionAvail().x / this->m_totalChild;

  /**
   * Ada jarak di kolom pertama dan itu annoying. Ini adlaah quick fix Jika 
   * ada yg punya solusi lebih bagus, saya senang hati menerimanya. :D 
   */
  bool firstColumn = true;

  if (ImGui::BeginTable("tableLayouts", this->m_totalChild)) {
    ImGui::TableNextRow();
    
    for (auto& obj : this->m_components) {
      ImGui::TableNextColumn();
      ImGui::SetNextItemWidth(width);

      if (firstColumn) {
        // set margin top
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 4.0f);
        firstColumn = false;        
      }

      obj->render();
    }

    ImGui::EndTable();
  }

  firstColumn = true;

  if (this->m_layouts.getSize() > 0) {
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 16.0f);

    if (ImGui::BeginTable("tableLayouts", this->m_layouts.getSize())) {
      ImGui::TableNextRow();
      
      for (auto& layout : this->m_layouts) {
        ImGui::TableNextColumn();
        ImGui::SetNextItemWidth(width);

        layout->render();
      }

      ImGui::EndTable();
    }
  }
}

void HBoxLayout::setId(std::string id) {
  this->m_id = id;
}
