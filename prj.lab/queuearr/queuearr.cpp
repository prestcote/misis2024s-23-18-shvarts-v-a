#include <queuearr/queuearr.hpp>

void QueueArr::Push(const Complex& new_element) {
  if (head_ + tail_ < 0) {
    size_ = 10;
    data_ = new Complex[10];
    head_ += 1;
    tail_ += 1;
    data_[tail_] = new_element;
  }
  else if (tail_ + 1 == head_ && head_) {
    data_ = new Complex[10];
    tail_ = 0;
    data_[tail_] = new_element;
  }
  else if (tail_ + 1 == head_ && head_ == 0) {

  }
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

