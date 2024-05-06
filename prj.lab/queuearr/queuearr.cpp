#include <queuearr/queuearr.hpp>

#include <stdexcept>
#include <cstdlib>
#include <algorithm>


QueueArr::QueueArr(const QueueArr& qu) { 
  if (!qu.IsEmpty()) {
    std::ptrdiff_t count = qu.Count();
    size_ = (count + 4) / 4 * 4;
    head_ = 0;
    tail_ = count - 1;
    //data_ = new Complex[size_];
    data_ = std::make_unique<Complex[]>(size_);
    if (qu.head_ < qu.tail_) {
      std::copy(qu.data_.get() + qu.head_, qu.data_.get() + qu.tail_ + 1, data_.get());
    }
    else {
      std::copy(qu.data_.get() + qu.head_, qu.data_.get() + qu.size_, data_.get());
      std::copy(qu.data_.get(), qu.data_.get() + qu.tail_ + 1, data_.get() + qu.size_ - qu.head_);
    }
  }
}



QueueArr& QueueArr::operator=(const QueueArr& copy) {
  if (this != &copy) {
    std::ptrdiff_t count = copy.Count();
    if (count == 0) {
      head_ -= 1;
    }
    else {
      if (size_ < count) {
        size_ = (count + 4) / 4 * 4;
        data_ = std::make_unique<Complex[]>(size_);
      }
      if (copy.head_ <= copy.tail_) {
        std::copy(copy.data_.get() + copy.head_, copy.data_.get() + copy.tail_ + 1, data_.get());
      }
      else {
        std::copy(copy.data_.get() + copy.head_, copy.data_.get() + copy.size_, data_.get());
        std::copy(copy.data_.get(), copy.data_.get() + copy.tail_ + 1, data_.get() + copy.size_ - copy.head_);
      }
      head_ = 0;
      tail_ = count - 1;
    }
  }
  return *this;
}


void QueueArr::Push(const Complex& val) {
  if (nullptr == data_) {
    size_ = 2;
    data_ = std::make_unique<Complex[]>(size_);
  }
  if (IsEmpty()) {
    head_ = 0;
    tail_ = 0;
  }
  else {
    if (head_ == (tail_ + 1) % size_) {
      auto new_data = std::make_unique<Complex[]>(size_ * 2);
      if (head_ <= tail_) {
        std::copy(data_.get() + head_, data_.get() + tail_ + 1, new_data.get());
      }
      else {
        std::copy(data_.get() + head_, data_.get() + size_, new_data.get());
        std::copy(data_.get(), data_.get() + tail_ + 1, new_data.get() + size_ - head_);
      }
      std::swap(data_, new_data);
      size_ *= 2;
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
    //counter -= 1;
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
  //return data_[head_];
  return data_[head_];
}

const Complex& QueueArr::Top() const{
  if (head_ == -1) {
    throw std::logic_error("empty queue");
  }
  //return data_[head_];
  return data_[head_];
}

Complex& QueueArr::Tail() {
  if (tail_ == -1) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  //return data_[tail_];
  return data_[tail_];
}

bool QueueArr::IsEmpty() const noexcept {
  return head_ < 0;
}

void QueueArr::Clear() noexcept {
  head_ = -1;
}

QueueArr::QueueArr(QueueArr&& copy) noexcept {
  tail_ = copy.tail_;
  copy.tail_ = -1;
  head_ = copy.head_;
  copy.head_ = -1;
  size_ = copy.size_;
  copy.size_ = 0;
  data_ = std::move(copy.data_);
}

QueueArr& QueueArr::operator=(QueueArr&& copy) noexcept {
  if (this != &copy) {
    size_ = copy.size_;
    head_ = copy.head_;
    tail_ = copy.tail_;
    data_ = std::move(copy.data_);

    copy.size_ = 0;
    copy.head_ = -1;
    copy.tail_ = -1;
  }
  return *this;
}

