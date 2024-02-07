#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>
#include <iostream>

StackArr::~StackArr() {
  if (data_) {
    delete[] data_;
  }
}

StackArr::StackArr(const StackArr& copy) {
  size_ = copy.size_;
  data_ = NULL;
  data_ = new Complex[size_];
  // WHAT AM I SUPPOSED TO DO NEXT
}

bool StackArr::IsEmpty(const StackArr&) noexcept {
  if (counter_ == 0) { return true; }
  else { return false; }
} 

const Complex& StackArr::Top(const StackArr&) {
  return *head_;
}

void StackArr::Pop(const StackArr&) noexcept{
  /////
}

void StackArr::Push(const StackArr&) {
  //////
}

StackArr StackArr::operator=(const StackArr&) {
  ///////
  return (*this);
}

