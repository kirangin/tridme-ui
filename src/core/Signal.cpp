#include <core/Signal.hpp>
using namespace Tridme;

void Signal::connect(const Slot& callable) {
  m_slots.pushBack(callable);
}

void Signal::emit() {
  for (auto& slot : m_slots) {
    slot();
  }
}