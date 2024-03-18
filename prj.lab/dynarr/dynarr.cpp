#include <iostream>
#include <sstream>
#include <dynarr/dynarr.hpp>

DynArr::~DynArr() {
  if (data_)
    delete[] data_;
}
DynArr::DynArr(const std::ptrdiff_t size) {
  if (size == 0) {
    throw std::invalid_argument("invalid size");
  }
  size_ = size;
  capacity_ = size;
  data_ = new float[size];
  for (int i = 0; i < size; i++) {
    (*this)[i] = 0;
  }
}

DynArr::DynArr(const DynArr& to_copy) {
  size_ = to_copy.size_;
  capacity_ = to_copy.capacity_;
  data_ = NULL;
  data_ = new float[size_];
  for (int i = 0; i < size_; i++) {
    data_[i] = to_copy[i];
  }
} 
/*
DynArr::DynArr(const DynArr& copy) {
  Resize(copy.Size());
  for (int i = 0; i < size_; ++i) {
    (*this)[i] = copy[i];
  }
}
*/
float& DynArr::operator[](const int64_t index) const{
  if (index >= size_ || index < 0) {
    throw std::invalid_argument("invalid index");
  }
  return *(data_ + index);
}

void DynArr::Resize(const std::ptrdiff_t size) {
  if (size <= 0) {
    throw std::invalid_argument("invalid size");
  }
  if (size < size_) {
    size_ = size;
  }
  else if (size > size_ && size <= capacity_) {
    std::ptrdiff_t size_old_ = size_;
    size_ = size;
    for (int i = size_old_; i < size_; ++i) {
      (*this)[i] = 0;
    }
  }
  else if (size > size_ && size > capacity_) {
    float* new_data = new float[size];
    for (int i = 0; i < size_; i++) {
      //*(new_data + i) = (*this)[i];
      new_data[i] = data_[i];
    }
    for (int i = size_; i < size; i++) {
      new_data[i] = 0;
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = size;
    size_ = size;
  }
  return;
}

DynArr& DynArr::operator=(const DynArr& to_copy) {
  Resize(to_copy.Size());
  for (int i = 0; i < size_; ++i) {
    (*this)[i] = to_copy[i];
  }
  return *this;
}

DynArr::DynArr(DynArr&& mov) noexcept {
  if (this != &mov) {
    data_ = mov.data_;
    capacity_ = mov.capacity_;
    size_ = mov.size_;
    mov.data_ = nullptr;
    mov.size_ = 0;
    mov.capacity_ = 0;
  }
}

DynArr& DynArr::operator=(DynArr&& mov) noexcept{
  if (this != &mov) {
    delete[] data_;
    data_ = mov.data_;
    capacity_ = mov.capacity_;
    size_ = mov.size_;
    mov.data_ = nullptr;
    mov.capacity_ = 0;
    mov.size_ = 0;
  }
  return *this;
}





