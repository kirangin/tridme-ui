#ifndef STACK_HPP
#define STACK_HPP

namespace Tridme {
  namespace Storage {
    template <typename T>
    class Stack {
      public:
        Stack();
        Stack(const Stack<T>& other);
        ~Stack();

        void push(const T& value);
        T pop();
        T peek();
        int getSize();

      private:
        T* data;
        int size;
    };

    #include "storage/Stack.inl"
  }
}

#endif