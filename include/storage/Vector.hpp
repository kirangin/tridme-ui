#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iterator>

/*
 * Vector dalam C++ != Vector dalam Matematika.
 *
 * Dalam c++, vector adalah array dinamis yang artinya ukurannya 
 * dapat berubah-ubah. Apa bedanya dengan array menggunakan pointer?
 * Sebenernya sama aja, tapi vector lebih mudah digunakan karena 
 * kita tidak perlu mengatur memori secara manual.
 */

namespace Tridme {
  namespace Storage {
    template <typename T>
    class Vector {
      public:
        Vector();
        ~Vector();

        /**
         * pushBack(data)
         * 
         * Menambahkan data ke dalam vector di bagian paling belakang.
         * 
         * @param data data yang ingin ditambahkan
         */
        void pushBack(const T& data);
        
        /*
        * popBack()
        *
        * Menghapus data di bagian paling belakang.
        */
        void popBack();

        /**
         * insert(data, index)
         * 
         * Menambahkan data ke dalam vector di bagian index yang ditentukan.
         * 
         * @param data data yang ingin ditambahkan
         * @param index index tempat data akan ditambahkan
         */
        void insert(const T& data, int index);

        /**
         * remove(index)
         * 
         * Menghapus data di bagian index yang ditentukan.
         * 
         * @param index index tempat data akan dihapus
         */
        void remove(int index);

        /*
        * clear()
        * 
        * Menghapus semua data di dalam vector.
        */
        void clear();

        /* 
         * Iterator (supaya bisa range-based for loop). 
         * Untuk iterator implementasinya langsung di sini aja.
         */
        class Iterator : public std::iterator<std::forward_iterator_tag, T> {
          public:
            Iterator(T* ptr) : ptr(ptr) {}
            Iterator operator++() { ptr++; return *this; }
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            bool operator==(const Iterator& rhs) const { return ptr == rhs.ptr; }
            bool operator!=(const Iterator& rhs) const { return ptr != rhs.ptr; }
            T& operator*() { return *ptr; }

          private:
            T* ptr;
        };


        Iterator begin();
        Iterator end();

        int getSize() const;
      private:
        T* data;
        int size;
        int capacity;
    };
  
    #include "storage/Vector.inl"
  }
}

#endif