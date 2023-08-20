#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

/* 
 * Vector2.hpp
 * 
 * Template untuk Vector 2 elemen beserta fungsi-fungsinya.
 */

namespace Tridme {
  namespace Storage {
    template <typename T>
    class Vector2 {
      public:
        Vector2();
        Vector2(const T& x, const T& y);
        Vector2(const Vector2<T>& other);
        ~Vector2();

        // Override semua operator
        Vector2<T> operator+(const Vector2<T>& other);
        Vector2<T> operator-(const Vector2<T>& other);
        Vector2<T> operator*(const Vector2<T>& other);
        Vector2<T> operator/(const Vector2<T>& other);
        Vector2<T> operator*(const T& other);
        Vector2<T> operator/(const T& other);
        Vector2<T> operator+=(const Vector2<T>& other);
        Vector2<T> operator-=(const Vector2<T>& other);
        Vector2<T> operator/=(const Vector2<T>& other);
        Vector2<T> operator*=(const Vector2<T>& other);
        Vector2<T> operator+=(const T& other);
        Vector2<T> operator-=(const T& other);
        Vector2<T> operator/=(const T& other);
        Vector2<T> operator*=(const T& other);

        // Fungsi-fungsi dasar vector
        T dot(const Vector2<T>& other);
        T cross(const Vector2<T>& other);
        T length();
        Vector2<T> normalize();

        T x, y;
    };
  
    #include "storage/Vector2.inl"
  };
};

#endif 