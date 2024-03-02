#include <queuearr/queuearr.hpp>
#include <stdexcept>
#include <cstdlib>

QueueArr::QueueArr(const QueueArr& qu) {
  if (!qu.IsEmpty()) {
    size_ = (tail_ + qu.size_ + 1 - head_) % qu.size_;
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
    data_ = new Complex[1];
    size_ = 1;
    head_ = 0;
    tail_ = 0;
  }
  else {
    if (head_ == (tail_ + 1) % size_) {
      std::ptrdiff_t newSize = size_ * 2;
      Complex* newData = new Complex[newSize];
      std::ptrdiff_t count = Count();
      for (std::ptrdiff_t i = 0; i < count; ++i) {
        newData[i] = data_[(head_ + i) % size_];
      }
      delete[] data_;
      data_ = newData;
      size_ = newSize;
      head_ = 0;
      tail_ = Count() - 1;
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
  return IsEmpty() ? 0 : (tail_ + size_ + 1 - head_) % size_;
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


