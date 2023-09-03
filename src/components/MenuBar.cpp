#include <components/MenuBar.hpp>
using namespace Tridme;
using namespace Tridme::UI;

MenuBar::MenuBar() {
  this->m_id = "##" + this->m_name;
}

MenuBar::~MenuBar() {
  for (auto menu : this->m_menus) {
    delete menu;
  }
}

void MenuBar::addMenu(Menu* menu) {
  this->m_menus.pushBack(menu);
}

void MenuBar::render() {
  if (ImGui::BeginMainMenuBar()) {
    for (auto menu : this->m_menus) {
      menu->render();
    }
    ImGui::EndMainMenuBar();
  }
}
