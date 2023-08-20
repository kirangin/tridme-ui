#include <components/Object.hpp>
using namespace Tridme;
using namespace Tridme::UI;

Object::Object() {
  
}

Object::~Object() {

}

void Object::show() {
  this->m_isVisible = true;
}

void Object::hide() {
  this->m_isVisible = false;
}

void Object::setVisible(bool value) {
  this->m_isVisible = value;
}

void Object::setId(const std::string& id) {
  this->id = id;
}
