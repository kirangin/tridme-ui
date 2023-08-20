#include <components/Layout.hpp>
using namespace Tridme;
using namespace Tridme::UI;

Layout::Layout() {
  this->m_components = Storage::Vector<Object*>();
  this->m_layouts = Storage::Vector<Layout*>();
}

Layout::~Layout() {
  this->m_components.clear();
  this->m_layouts.clear();
}

void Layout::render() {
  for (auto& component : this->m_components) {
    component->render();
  }

  for (auto& layout : this->m_layouts) {
    layout->render();
  }
}

void Layout::addComponent(Object* obj) {
  this->m_components.pushBack(obj);
  this->m_ids.pushBack(obj->getId());
}

void Layout::addLayout(Layout* layout) {
  this->m_layouts.pushBack(layout);
}

void Layout::removeComponent(Object* obj) {
  // TODO:: implement
}

void Layout::removeLayout(Layout* layout) {
  // TODO: implement
}

void Layout::clearComponents() {
  this->m_components.clear();
}

void Layout::clearLayouts() {
  this->m_layouts.clear();
}

