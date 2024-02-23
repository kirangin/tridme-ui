#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iterator>

namespace Tridme {
  namespace Storage {
    template <typename T>
    class Queue {
      public:
        Queue();
        Queue(const Queue<T>& queue);
        ~Queue();

        void push(T value);
        T pop();
        T front();
        T back();
        bool empty();
        int getSize();
        
        class Iterator : public std::iterator<std::input_iterator_tag, T> {
          public:
            Iterator(T* ptr);
            Iterator operator++();
            Iterator operator++(int);
            bool operator==(const Iterator& other);
            bool operator!=(const Iterator& other);
            T& operator*();
          private:
            T* ptr;
        };

        Iterator begin();
        Iterator end();

      private:
        T* data;
        int size;
    };  
  
    #include "storage/Queue.inl"
  }
}

#endif