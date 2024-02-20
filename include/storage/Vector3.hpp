#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>

/* 
 * Vector3.hpp
 * 
 * Template untuk Vector 3 elemen beserta fungsi-fungsinya.
 */

namespace Tridme {
  namespace Storage {
    template <typename T>
    class Vector3 {
      public:
        Vector3();
        Vector3(const T& x, const T& y, const T& z);
        Vector3(const Vector3<T>& other);
        ~Vector3();

        // Override semua operator
        Vector3<T> operator+(const Vector3<T>& other);
        Vector3<T> operator-(const Vector3<T>& other);
        Vector3<T> operator*(const Vector3<T>& other);
        Vector3<T> operator/(const Vector3<T>& other);
        Vector3<T> operator*(const T& other);
        Vector3<T> operator/(const T& other);
        Vector3<T> operator+=(const Vector3<T>& other);
        Vector3<T> operator-=(const Vector3<T>& other);
        Vector3<T> operator/=(const Vector3<T>& other);
        Vector3<T> operator*=(const Vector3<T>& other);
        Vector3<T> operator+=(const T& other);
        Vector3<T> operator-=(const T& other);
        Vector3<T> operator/=(const T& other);
        Vector3<T> operator*=(const T& other);

        // Fungsi-fungsi dasar vector
        T dot(const Vector3<T>& other);
        T cross(const Vector3<T>& other);
        T length();
        Vector3<T> normalize();

        T x, y, z;
    };
  
    #include "storage/Vector3.inl"
  };
};

#endif 