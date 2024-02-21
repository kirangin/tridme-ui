#ifndef STACK_INL
#define STACK_INL

template <typename T> Stack<T>::Stack() {
  this->data = new T[0];
  this->size = 0;
}

template <typename T> Stack<T>::Stack(const Stack<T>& other) {
  this->data = new T[other.size];
  this->size = other.size;

  for (int i = 0; i < other.size; i++) {
    this->data[i] = other.data[i];
  }
}

template <typename T> Stack<T>::~Stack() {
  delete[] this->data;
}

template <typename T> void Stack<T>::push(const T& value) {
  T* temp = new T[this->size + 1];

  for (int i = 0; i < this->size; i++) {
    temp[i] = this->data[i];
  }

  temp[this->size] = value;

  delete[] this->data;
  this->data = temp;
  this->size++;
}

template <typename T> T Stack<T>::pop() {
  T* temp = new T[this->size - 1];

  for (int i = 0; i < this->size - 1; i++) {
    temp[i] = this->data[i];
  }

  T value = this->data[this->size - 1];

  delete[] this->data;
  this->data = temp;
  this->size--;

  return value;
}

template <typename T> T Stack<T>::peek() {
  return this->data[this->size - 1];
}

template <typename T> int Stack<T>::getSize() {
  return this->size;
}

#endif