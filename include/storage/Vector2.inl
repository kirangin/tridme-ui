#ifndef VECTOR2_INL
#define VECTOR2_INL

template <typename T> Vector2<T>::Vector2() {
  this->x = 0;
  this->y = 0;
}

template <typename T> Vector2<T>::Vector2(const T& x, const T& y) {
  this->x = x;
  this->y = y;
}

template <typename T> Vector2<T>::Vector2(const Vector2<T>& other) {
  this->x = other.x;
  this->y = other.y;
}

template <typename T> Vector2<T>::~Vector2() {
  // nothing to do here
}

// Ini mungkin bakal jadi pusing karena antara template <typename T> fungsinya nggak pake new line
// tapi untuk menghemat line number, jadi ya, wayahna.
template <typename T> Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) {
  Vector2<T> result;

  result.x = this->x + other.x;
  result.y = this->y + other.y;

  return result;
}

template <typename T> Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) {
  Vector2<T> result;

  result.x = this->x - other.x;
  result.y = this->y - other.y;

  return result;
}

template <typename T> Vector2<T> Vector2<T>::operator*(const Vector2<T>& other) {
  Vector2<T> result;

  result.x = this->x * other.x;
  result.y = this->y * other.y;

  return result;
}

template <typename T> Vector2<T> Vector2<T>::operator/(const Vector2<T>& other) {
  Vector2<T> result;

  result.x = this->x / other.x;
  result.y = this->y / other.y;

  return result;
}

template <typename T> Vector2<T> Vector2<T>::operator*(const T& other) {
  Vector2<T> result;

  result.x = this->x * other;
  result.y = this->y * other;

  return result;
}

template <typename T> Vector2<T> Vector2<T>::operator/(const T& other) {
  Vector2<T> result;

  result.x = this->x / other;
  result.y = this->y / other;

  return result;
}

template <typename T> Vector2<T> Vector2<T>::operator+=(const Vector2<T>& other) {  
  this->x += other.x;
  this->y += other.y;

  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator-=(const Vector2<T>& other) {  
  this->x -= other.x;
  this->y -= other.y;

  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator*=(const Vector2<T>& other) {  
  this->x *= other.x;
  this->y *= other.y;

  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator/=(const Vector2<T>& other) {  
  this->x /= other.x;
  this->y /= other.y;

  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator+=(const T& other) {  
  this->x += other;
  this->y += other;

  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator-=(const T& other) {  
  this->x -= other;
  this->y -= other;

  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator*=(const T& other) {  
  this->x *= other;
  this->y *= other;

  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator/=(const T& other) {  
  this->x /= other;
  this->y /= other;

  return *this;
}

// Fungsi-fungsi dasar vector
template <typename T> T Vector2<T>::dot(const Vector2<T>& other) {
  return x * other.x + y * other.y;
}

template <typename T> T Vector2<T>::cross(const Vector2<T>& other) {
  return x * other.y - y * other.x;
}

template <typename T> T Vector2<T>::length() {
  return sqrt(this->x * this->x + this->y * this->y);
}

template <typename T> Vector2<T> Vector2<T>::normalize() {
  return *this->length();
}

#endif