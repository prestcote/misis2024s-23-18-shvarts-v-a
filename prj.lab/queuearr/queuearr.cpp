#include <queuearr/queuearr.hpp>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

QueueArr::QueueArr(const QueueArr& qu) { 
  if (!qu.IsEmpty()) {
    //size_ = (qu.tail_ + qu.size_ - qu.head_) % qu.size_ + 1;
    size_ = qu.Count();
    head_ = 0;
    tail_ = size_ - 1;
    data_ = new Complex[size_];
    if (qu.head_ < qu.tail_) {
      std::copy(qu.data_ + qu.head_, qu.data_ + qu.tail_ + 1, data_);
    }
    else {
      std::copy(qu.data_ + qu.head_, qu.data_ + qu.size_ + 1, data_);
      std::copy(qu.data_, qu.data_ + qu.tail_ + 1, data_ + qu.size_ - qu.head_);
    }
  }
}

QueueArr& QueueArr::operator=(const QueueArr& copy) {
  if (this != &copy) {
    Clear();
    if (!copy.IsEmpty()) {
      //size_ = (qu.tail_ + qu.size_ - qu.head_) % qu.size_ + 1;
      size_ = copy.Count();
      head_ = 0;
      tail_ = size_ - 1;
      data_ = new Complex[size_];
      if (copy.head_ < copy.tail_) {
        std::copy(copy.data_ + copy.head_, copy.data_ + copy.tail_ + 1, data_);
      }
      else {
        std::copy(copy.data_ + copy.head_, copy.data_ + copy.size_ + 1, data_);
        std::copy(copy.data_, copy.data_ + copy.tail_ + 1, data_ + copy.size_ - copy.head_);
      }
    }
    return *this;
  }
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
      //tail_ = Count();
      tail_ = counter;
    }
    else {
      tail_ = (tail_ + 1) % size_;
    }
  }
  data_[tail_] = val;
  counter += 1;
}

void QueueArr::Pop() noexcept {
  if (!IsEmpty()) {
    if (head_ != tail_) {
      head_ = (head_ + 1) % size_;
    }
    else {
      head_ = -1;
    }
    counter -= 1;
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


