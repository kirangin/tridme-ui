#ifndef VECTOR3_INL
#define VECTOR3_INL

template <typename T> Vector3<T>::Vector3() {
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

template <typename T> Vector3<T>::Vector3(const T& x, const T& y, const T& z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

template <typename T> Vector3<T>::Vector3(const Vector3<T>& other) {
  this->x = other.x;
  this->y = other.y;
  this->z = other.z;
}

template <typename T> Vector3<T>::~Vector3() {}

template <typename T> Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) {
  return Vector3<T>(this->x + other.x, this->y + other.y, this->z + other.z);
}

template <typename T> Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) {
  return Vector3<T>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template <typename T> Vector3<T> Vector3<T>::operator*(const Vector3<T>& other) {
  return Vector3<T>(this->x * other.x, this->y * other.y, this->z * other.z);
}

template <typename T> Vector3<T> Vector3<T>::operator/(const Vector3<T>& other) {
  return Vector3<T>(this->x / other.x, this->y / other.y, this->z / other.z);
}

template <typename T> Vector3<T> Vector3<T>::operator*(const T& other) {
  return Vector3<T>(this->x * other, this->y * other, this->z * other);
}

template <typename T> Vector3<T> Vector3<T>::operator/(const T& other) {
  return Vector3<T>(this->x / other, this->y / other, this->z / other);
}

template <typename T> Vector3<T> Vector3<T>::operator+=(const Vector3<T>& other) {
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;
}

template <typename T> Vector3<T> Vector3<T>::operator-=(const Vector3<T>& other) {
  this->x -= other.x;
  this->y -= other.y;
  this->z -= other.z;
  return *this;
}

template <typename T> Vector3<T> Vector3<T>::operator/=(const Vector3<T>& other) {
  this->x /= other.x;
  this->y /= other.y;
  this->z /= other.z;
  return *this;
}

template <typename T> Vector3<T> Vector3<T>::operator*=(const Vector3<T>& other) {
  this->x *= other.x;
  this->y *= other.y;
  this->z *= other.z;
  return *this;
}

template <typename T> Vector3<T> Vector3<T>::operator+=(const T& other) {
  this->x += other;
  this->y += other;
  this->z += other;
  return *this;
}

template <typename T> Vector3<T> Vector3<T>::operator-=(const T& other) {
  this->x -= other;
  this->y -= other;
  this->z -= other;
  return *this;
}

template <typename T> Vector3<T> Vector3<T>::operator/=(const T& other) {
  this->x /= other;
  this->y /= other;
  this->z /= other;
  return *this;
}

template <typename T> Vector3<T> Vector3<T>::operator*=(const T& other) {
  this->x *= other;
  this->y *= other;
  this->z *= other;
  return *this;
}

template <typename T> T Vector3<T>::dot(const Vector3<T>& other) {
  return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

template <typename T> T Vector3<T>::cross(const Vector3<T>& other) {
  return (this->x * other.x) - (this->y * other.y) - (this->z * other.z);
}

template <typename T> T Vector3<T>::length() {
  return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

template <typename T> Vector3<T> Vector3<T>::normalize() {
  T length = this->length();
  return Vector3<T>(this->x / length, this->y / length, this->z / length);
}


#endif