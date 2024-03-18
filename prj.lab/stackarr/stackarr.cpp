#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>

#include <iostream>
#include <stdexcept>
#include <algorithm>


StackArr::~StackArr() {
  if (data_) {
    delete[] data_;
    head_ = 0;
    size_ = 0;
  }
} 

StackArr::StackArr(const StackArr& copy) {
  size_ = copy.head_ + 1;
  //data_ = nullptr;
  head_ = copy.head_;
  data_ = new Complex[size_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = copy.data_[i];
  }
}

bool StackArr::IsEmpty() const noexcept {
  return (head_ == -1);
} 

Complex& StackArr::Top() {
  if (head_ < 0) {
    throw std::exception("stack underflow");
  }
  return *(data_ + head_);
}

const Complex& StackArr::Top() const {
  if (head_ < 0) {
    throw std::exception("stack underflow");
  }
  return *(data_ + head_);
}
void StackArr::Pop() noexcept{
  if (head_ > -1) {
    //std::cout << *(data_ + head_);
    head_ -= 1;
  }
}

void StackArr::Push(const Complex& new_element) {
  if (head_+1 < size_) {
    head_ += 1;
    //*(data_ + head_) = new_element;
    data_[head_] = new_element;
  }
  else {
    if (size_ == 0) {
      size_ = 2;
      head_ += 1;
      data_ = new Complex[size_];
     //*(data_ + head_) = new_element;
      data_[head_] = new_element;
    }
    else {
      std::ptrdiff_t new_size = size_ * 2;
      Complex* new_data = new Complex[new_size];
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

StackArr& StackArr::operator=(const StackArr& copy) {
  if (this != &copy) {
    if (size_ == 0) {
      size_ = copy.head_ + 1;
      data_ = new Complex[size_];
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
        Complex* new_data = new Complex[copy.size_];
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

void StackArr::Clear() noexcept {
  head_ = -1;
  size_ = 0;
}

StackArr::StackArr(StackArr&& copy) {
  if (this != &copy) {
    size_ = copy.size_;
    head_ = copy.head_;
    data_ = copy.data_;
    copy.data_ = nullptr;
    copy.size_ = 0;
    copy.head_ = 0;
  }
}

StackArr& StackArr::operator=(StackArr&& copy) {
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

