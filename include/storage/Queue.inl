#ifndef QUEUE_INL
#define QUEUE_INL

template <typename T> Queue<T>::Queue() {
  this->data = new T[0];
  this->size = 0;
}

template <typename T> Queue<T>::Queue(const Queue<T>& other) {
  this->data = new T[other.size];
  this->size = other.size;

  for (int i = 0; i < other.size; i++) {
    this->data[i] = other.data[i];
  }
}

template <typename T> Queue<T>::~Queue() {
  delete[] this->data;
}

template <typename T> void Queue<T>::push(T value) {
  T* temp = new T[this->size + 1];

  for (int i = 0; i < this->size; i++) {
    temp[i] = this->data[i];
  }

  temp[this->size] = value;

  delete[] this->data;
  this->data = temp;
  this->size++;
}

template <typename T> T Queue<T>::pop() {
  T* temp = new T[this->size - 1];

  for (int i = 0; i < this->size - 1; i++) {
    temp[i] = this->data[i + 1];
  }

  T value = this->data[0];

  delete[] this->data;
  this->data = temp;
  this->size--;

  return value;
}

template <typename T> T Queue<T>::front() {
  return this->data[0];
}

template <typename T> T Queue<T>::back() {
  return this->data[this->size - 1];
}

template <typename T> bool Queue<T>::empty() {
  return this->size == 0;
}

template <typename T> int Queue<T>::getSize() {
  return this->size;
}

template <typename T> typename Queue<T>::Iterator Queue<T>::begin() {
  return Iterator(this->data);
}

template <typename T> typename Queue<T>::Iterator Queue<T>::end() {
  return Iterator(this->data + this->size);
}

template <typename T> Queue<T>::Iterator::Iterator(T* ptr) : ptr(ptr) {}

template <typename T> typename Queue<T>::Iterator Queue<T>::Iterator::operator++() {
  ptr++;
  return *this;
}

template <typename T> typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {
  Iterator temp = *this;
  ptr++;
  return temp;
}

template <typename T> bool Queue<T>::Iterator::operator==(const Iterator& other) {
  return ptr == other.ptr;
}

template <typename T> bool Queue<T>::Iterator::operator!=(const Iterator& other) {
  return ptr != other.ptr;
}

template <typename T> T& Queue<T>::Iterator::operator*() {
  return *ptr;
}

#endif