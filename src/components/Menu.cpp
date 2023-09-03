#include <components/Menu.hpp>
using namespace Tridme;
using namespace Tridme::UI;

Menu::Menu(std::string label) {
  this->m_name = label;
  this->m_id = "##" + this->m_name;
}

Menu::~Menu() {
  this->m_actions.clear();
  this->m_items.clear();
}

void Menu::addItem(std::string label, std::string id) {
  this->m_items.pushBack(std::pair<std::string, std::string>(id, label));
}

void Menu::addItem(std::string label, std::string shortcut, std::string id) {
  this->m_items.pushBack(std::pair<std::string, std::string>(id, label));
  this->m_shortcuts.insert(std::pair<std::string, std::string>(id, shortcut));
}

void Menu::addAction(std::string id, const Slot& callable) {
  Signal* action = new Signal();
  action->connect(callable);
  this->m_actions[id] = action;
}

void Menu::render() {
  if (ImGui::BeginMenu(this->m_name.c_str())) {
    for (auto item : this->m_items) {
      if (this->m_shortcuts.find(item.first) != this->m_shortcuts.end()) {
        if (ImGui::MenuItem(item.second.c_str(), this->m_shortcuts[item.first].c_str())) {
          if (this->m_actions[item.first] != nullptr) {
            this->m_actions[item.first]->emit();
          }
        }
      } else {
        if (ImGui::MenuItem(item.second.c_str())) {
          if (this->m_actions[item.first] != nullptr) {
            this->m_actions[item.first]->emit();
          }
        }
      }
    }
    ImGui::EndMenu();
  }
}