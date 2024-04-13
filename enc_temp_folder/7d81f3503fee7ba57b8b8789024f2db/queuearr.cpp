#include <queuearr/queuearr.hpp>

#include <stdexcept>
#include <cstdlib>
#include <algorithm>

QueueArr::~QueueArr() {
  head_ = -1;
  tail_ = -1;
  size_ = 0;
  data_ = nullptr;
}

QueueArr::QueueArr(const QueueArr& qu) { 
  if (!qu.IsEmpty()) {
    size_ = (qu.Count() + 4) / 4 * 4;
    head_ = 0;
    tail_ = qu.Count() - 1;
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
    Clear();
    if (!copy.IsEmpty()) {
      head_ = 0;
      tail_ = copy.Count() - 1;
      if (size_ < copy.Count()) {
        size_ = (copy.Count() + 4) / 4 * 4;
        data_ = std::make_unique<Complex[]>(size_);
      }
      if (copy.head_ < copy.tail_) {
        std::copy(copy.data_.get() + copy.head_, copy.data_.get() + copy.tail_ + 1, data_.get());
      }
      else {
        std::copy(copy.data_.get() + copy.head_, copy.data_.get() + copy.size_, data_.get());
        std::copy(copy.data_.get(), copy.data_.get() + copy.tail_ + 1, data_.get() + copy.size_ - copy.head_);
      }
    }
  }
  return *this;
}


void QueueArr::Push(const Complex& val) {
  if (nullptr == data_) {
    data_.reset(new Complex[1]);
    head_ = 0;
    tail_ = 0;
    size_ = 1;
  }
  else {
    if (head_ == (tail_ + 1) % size_) {
      std::ptrdiff_t new_size = size_ * 2;
      //std::unique_ptr<Complex> new_data = std::make_unique<Complex>(new_size);
      std::unique_ptr<Complex[]> new_data(new Complex[new_size]);
      std::ptrdiff_t count = Count();
      for (int i = 0; i < count; i++) {
        //new_data[i] = data_[(head_ + i) % size_];
        *(new_data.get() + i) = *(data_.get() + ((head_ + i) % size_));
      }
      data_.reset(new_data.release());
      size_ = new_size;
      head_ = 0;
      //tail_ = Count();
      tail_ = counter;
    }
    else {
      tail_ = (tail_ + 1) % size_;
    }
  }
  //data_[tail_] = val;
  *(data_.get() + tail_) = val;
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
  //return data_[head_];
  return *(data_.get() + head_);
}

const Complex& QueueArr::Top() const{
  if (head_ == -1) {
    throw std::logic_error("empty queue");
  }
  //return data_[head_];
  return *(data_.get() + head_);
}

Complex& QueueArr::Tail() {
  if (tail_ == -1) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  //return data_[tail_];
  return *(data_.get() + tail_);
}

bool QueueArr::IsEmpty() const noexcept {
  return head_ < 0;
}

void QueueArr::Clear() noexcept {
  head_ = -1;
  tail_ = -1;
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
    std::swap(tail_, copy.tail_);
    std::swap(head_, copy.head_);
    data_ = std::move(copy.data_);
  }
  return *this;
}

