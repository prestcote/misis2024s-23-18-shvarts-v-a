#pragma once
#ifndef STACKARRT_STACKARRT_HPP
#define STACKARRT_STACKARRT_HPP

//#include <complex/complex.hpp>
#include <cstddef>
#include <cstdlib>

template <typename T>
class StackArrT {
public:
  StackArrT() = default;
  StackArrT(const StackArrT& copy);
  StackArrT(StackArrT&& copy);
  ~StackArrT();
  StackArrT& operator=(const StackArrT& copy);
  StackArrT& operator=(StackArrT&& copy);

  void Push(const T& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;

  T& Top();
  const T& Top() const;

  void Clear() noexcept;

  std::ptrdiff_t Size() const { return size_; }
  std::ptrdiff_t Head() const { return head_; }

private:
  std::ptrdiff_t size_ = 0;
  T* data_ = nullptr;
  std::ptrdiff_t head_ = -1;
};

template <typename T>
StackArrT<T>::~StackArrT() {
  if (data_) {
    delete[] data_;
    head_ = 0;
    size_ = 0;
  }
}

template <typename T>
StackArrT<T>::StackArrT(const StackArrT& copy) {
  size_ = copy.head_ + 1;
  //data_ = nullptr;
  head_ = copy.head_;
  data_ = new T[size_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = copy.data_[i];
  }
}

template <typename T>
bool StackArrT<T>::IsEmpty() const noexcept {
  return (head_ == -1);
}

template <typename T>
T& StackArrT<T>::Top() {
  if (head_ < 0) {
    throw std::exception("stack underflow");
  }
  return *(data_ + head_);
}

template <typename T>
const T& StackArrT<T>::Top() const {
  if (head_ < 0) {
    throw std::exception("stack underflow");
  }
  return *(data_ + head_);
}

template <typename T>
void StackArrT<T>::Pop() noexcept {
  if (head_ > -1) {
    //std::cout << *(data_ + head_);
    head_ -= 1;
  }
}

template <typename T>
void StackArrT<T>::Push(const T& new_element) {
  if (head_ + 1 < size_) {
    head_ += 1;
    //*(data_ + head_) = new_element;
    data_[head_] = new_element;
  }
  else {
    if (size_ == 0) {
      size_ = 2;
      head_ += 1;
      data_ = new T[size_];
      //*(data_ + head_) = new_element;
      data_[head_] = new_element;
    }
    else {
      std::ptrdiff_t new_size = size_ * 2;
      T* new_data = new T[new_size];
      for (int i = 0; i < size_; i++) {
        //*(new_data + i) = (*this)[i];
        new_data[i] = data_[i];
      }
      delete[] data_;
      data_ = new_data;
      size_ *= 2;
      head_ += 1;
      //*(data_ + head_) = new_element;
      data_[head_] = new_element;
    }
  }
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT& copy) {
  if (this != &copy) {
    if (size_ == 0) {
      size_ = copy.head_ + 1;
      data_ = new T[size_];
      head_ = copy.head_;
      for (int i = 0; i < size_; ++i) {
        data_[i] = copy.data_[i];
      }
    }
    else {
      if (size_ >= copy.size_) {
        size_ = copy.size_;
        head_ = copy.head_;
        for (int i = 0; i < copy.size_; i++) {
          data_[i] = copy.data_[i];
        }
      }
      else {
        T* new_data = new T[copy.size_];
        for (int i = 0; i < copy.size_; i++) {
          new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        size_ = copy.size_;
        head_ = copy.head_;
      }
    }
  }
  return (*this);
}

template <typename T>
void StackArrT<T>::Clear() noexcept {
  head_ = -1;
  size_ = 0;
}

template <typename T>
StackArrT<T>::StackArrT(StackArrT&& copy) {
  if (this != &copy) {
    size_ = copy.size_;
    head_ = copy.head_;
    data_ = copy.data_;
    copy.data_ = nullptr;
    copy.size_ = 0;
    copy.head_ = 0;
  }
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT&& copy) {
  if (this != &copy) {
    size_ = copy.size_;
    head_ = copy.head_;
    data_ = copy.data_;
    copy.data_ = nullptr;
    copy.size_ = 0;
    copy.head_ = 0;
  }
  return *this;
}

#endif