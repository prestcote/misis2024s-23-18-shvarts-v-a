#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>
#include <iostream>

StackArr::~StackArr() {
  if (data_) {
    delete[] data_;
  }
}

StackArr::StackArr(const StackArr& copy) {
  size_ = copy.head_ + 1;
  data_ = NULL;
  head_ = copy.head_;
  Complex* data_ = new Complex[size_];
  for (int i = 0; i < size_; i++) {
    //data_[i] = *(copy.data_ + i);
    data_[i] = copy.data_[i];
  }
}

bool StackArr::IsEmpty() noexcept {
  return !(head_ >= 0);
} 

const Complex& StackArr::Top() {
  return *(data_ + head_);
}

void StackArr::Pop() noexcept{
  if (head_ > -1) {
    std::cout << *(data_ + head_);
    head_ -= 1;
  }
}

void StackArr::Push(Complex& new_element) {
  if (head_+1 < size_) {
    head_ += 1;
    //*(data_ + head_) = new_element;
    data_[head_] = new_element;
  }
  else {
    if (size_ == 0) {
      size_ = 12;
      head_ += 1;
      Complex* data_ = new Complex[15];
      for (int i = 0; i < size_; i++) {
        data_[i] = Complex(0, 0);
      }
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
      for (int i = size_; i < new_size; i++) {
        new_data[i] = Complex(0, 0);
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

StackArr StackArr::operator=(const StackArr& copy) {
  if (size_ == 0) {
    size_ = copy.size_;
    Complex* data_ = new Complex[size_];
    head_ = copy.head_;
    for (int i = 0; i < copy.size_; i++) {
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
      for (int i = copy.size_; i < size_; i++) {
        data_[i] = Complex();
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
  return (*this);
}

