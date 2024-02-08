#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>
#include <iostream>

StackArr::~StackArr() {
  if (data_) {
    delete[] data_;
  }
}

StackArr::StackArr(const StackArr& copy) {
  size_ = copy.counter_;
  data_ = NULL;
  counter_ = copy.counter_;
  data_ = new Complex[size_];
  for (int i = 0; i < size_; i++) {
    data_[i] = *(copy.data_ + i);
  }
}

bool StackArr::IsEmpty() noexcept {
  return !(counter_ > 0);
} 

const Complex& StackArr::Top() {
  return *head_;
}

void StackArr::Pop() noexcept{
  if (counter_ > 0) {
    std::cout << *(data_ + counter_);
    counter_ -= 1;
  }
}

void StackArr::Push(Complex& new_element) {
  if (counter_+1 < size_) {
    *(data_ + counter_) = new_element;
    //data_[counter_] = new_element;
    counter_ += 1;
  }
  else {
    if (size_ == 0) {
      size_ = 10;
      Complex* data_ = new Complex[size_];
      for (int i = size_; i < size_; i++) {
        data_[i] = Complex();
      }
      *(data_ + counter_) = new_element;
      //data_[counter_ + 1] = new_element;
      counter_ += 1;
    }
    else {
      Complex* new_data = new Complex[size_];
      for (int i = 0; i < size_; i++) {
        //*(new_data + i) = (*this)[i];
        new_data[i] = data_[i];
      }
      for (int i = size_; i < size_*2; i++) {
        new_data[i] = Complex();
      }
      delete[] data_;
      data_ = new_data;
      size_ *= 2;
      counter_ += 1;
      //*(data_ + counter_) = new_element;
      data_[counter_] = new_element;
    }
  }
}

StackArr StackArr::operator=(const StackArr& copy) {
  if (size_ == 0) {
    size_ = copy.size_;
    Complex* data_ = new Complex[size_];
    counter_ = copy.counter_;
    for (int i = 0; i < copy.size_; i++) {
      data_[i] = copy.data_[i];
    }
  }
  if (size_ >= copy.size_) {
    size_ = copy.size_;
    counter_ = copy.counter_;
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
    counter_ = copy.counter_;
  }
  return (*this);
}

