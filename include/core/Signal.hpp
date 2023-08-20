#ifndef SIGNAL_HPP
#define SIGNAL_HPP
#include <iostream>
#include <functional>
#include <storage/Vector.hpp>

/*
 * Kita menggunakan signal dan slot untuk menghubungkan antar object.
 */

namespace Tridme {
  class Signal {
    public:
      using Slot = std::function<void()>;

      void connect(const Slot& callable);
      void emit();

    private:
      Storage::Vector<Slot> m_slots;
  };  
};

#endif