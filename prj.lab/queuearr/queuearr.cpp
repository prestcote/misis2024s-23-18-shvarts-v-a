#include <queuearr/queuearr.hpp>
#include <stdexcept>
#include <cstdlib>

QueueArr::QueueArr(const QueueArr& qu) {
  if (!qu.IsEmpty()) {
    size_ = (tail_ + qu.size_ - head_) % qu.size_ + 1;
    head_ = 0;
    tail_ = size_;
    size_ = (size_ + 4) / 4 * 4;
    data_ = new Complex[size_];
    if (qu.head_ < qu.tail_) {
      std::copy(qu.data_ + qu.head_, qu.data_ + qu.tail_, data_);
    }
    else {
      std::copy(qu.data_ + qu.head_, qu.data_ + qu.size_, data_);
      std::copy(qu.data_, qu.data_ + qu.tail_, data_ + qu.size_);
    }
  }
}

QueueArr::~QueueArr() {
  delete[] data_;
}


void QueueArr::Push(const Complex& val) {
  if (nullptr == data_) {
    data_ = new Complex[1];
    head_ = 0;
    tail_ = 0;
    size_ = 1;
  }
  else {
    if (head_ == (tail_ + 1) % size_) {
      std::ptrdiff_t new_size = size_ * 2;
      Complex* new_data = new Complex[new_size];
      std::ptrdiff_t count = Count();
      for (int i = 0; i < count; i++) {
        //*(new_data + i) = (*this)[i];
        new_data[i] = data_[(head_ + i) % size_];
      }
      delete[] data_;
      data_ = new_data;
      size_ = new_size;
      head_ = 0;
      tail_ = Count();
    }
    else {
      tail_ = (tail_ + 1) % size_;
    }
  }
  data_[tail_] = val;
}

void QueueArr::Pop() noexcept {
  if (!IsEmpty()) {
    if (head_ != tail_) {
      head_ = (head_ + 1) % size_;
    }
    else {
      head_ = -1;
    }
  }
}


std::ptrdiff_t QueueArr::Count() const {
  if (head_ == -1 || tail_ == -1) {
    return 0;
  }
  return (tail_ - head_ + size_) % size_ + 1;
}

Complex& QueueArr::Top() {
  if (head_ == -1) {
    throw std::logic_error("empty queue");
  }
  return data_[head_];
}

const Complex& QueueArr::Top() const{
  if (head_ == -1) {
    throw std::logic_error("empty queue");
  }
  return data_[head_];
}

Complex& QueueArr::Tail() {
  if (tail_ == -1) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return data_[tail_];
}

bool QueueArr::IsEmpty() const noexcept {
  return head_ < 0;
}

void QueueArr::Clear() noexcept {
  head_ = -1;
}


