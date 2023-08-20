#ifndef VECTOR_INL
#define VECTOR_INL

template <typename T> Vector<T>::Vector() {
  this->size = 0;
  this->capacity = 0;
  this->data = nullptr;
}

template <typename T> Vector<T>::~Vector() {
  delete[] this->data;
}

template <typename T> void Vector<T>::pushBack(const T& data) {
  // Jika size == capacity, maka kita harus menambahkan kapasitas vector
  // sebelum menambahkan data.
  if (this->size == this->capacity) {
    this->capacity = this->capacity == 0 ? 1 : this->capacity * 2;
    T* temp = new T[this->capacity];

    for (int i = 0; i < this->size; i++) {
      temp[i] = this->data[i];
    }

    delete[] this->data;
    this->data = temp;
  }

  this->data[this->size] = data;
  this->size++;
}

template <typename T> void Vector<T>::popBack() {
  if (this->size > 0) {
    this->size--;
  }
}

template <typename T> void Vector<T>::insert(const T& data, int index) {
  if (index >= 0 && index <= this->size) {
    if (this->size == this->capacity) {
      this->capacity = this->capacity == 0 ? 1 : this->capacity * 2;
      T* temp = new T[this->capacity];
      
      for (int i = 0; i < this->size; i++) {
        temp[i] = this->data[i];
      }

      delete[] this->data;
      this->data = temp;
    }
    
    for (int i = this->size; i > index; i--) {
      this->data[i] = this->data[i - 1];
    }

    this->data[index] = data;
    this->size++;
  }
}

template <typename T> void Vector<T>::remove(int index) {
  if (index >= 0 && index < this->size) {
    for (int i = index; i < this->size - 1; i++) {
      this->data[i] = this->data[i + 1];
    }
    this->size--;
  }
}

template <typename T> void Vector<T>::clear() {
  this->size = 0;
}

template <typename T> typename Vector<T>::Iterator Vector<T>::begin() {
  return Iterator(this->data);
}

template <typename T> typename Vector<T>::Iterator Vector<T>::end() {
  return Iterator(this->data + this->size);
}

template <typename T> int Vector<T>::getSize() const {
  return this->size;
}

#endif