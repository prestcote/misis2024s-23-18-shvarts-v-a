#pragma once
#ifndef QUEUEARRT_HPP_HPP
#define QUEUEARRT_HPP_HPP

//#include <complex/complex.hpp>
#include <cstdlib>
#include <cstddef>
#include <memory>

template <typename T>
class QueueArrT {
public:
  QueueArrT() = default;;
  ~QueueArrT() = default;
  QueueArrT(const QueueArrT& copy);
  QueueArrT(QueueArrT&& copy) noexcept;

  QueueArrT& operator=(const QueueArrT& copy);
  QueueArrT& operator=(QueueArrT&& copy) noexcept;

  void Push(const T& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  T& Top();
  const T& Top() const;
  void Clear() noexcept;

  T& Tail();
  std::ptrdiff_t Size() {
    return size_;
  }

private:
  std::unique_ptr<T[]> data_ = nullptr;
  std::ptrdiff_t head_ = -1;
  std::ptrdiff_t tail_ = -1;
  std::ptrdiff_t size_ = 0;

  std::ptrdiff_t Count() const;
  std::ptrdiff_t counter = 0;
};

template <typename T>
QueueArrT<T>::QueueArrT(const QueueArrT& qu) {
  if (!qu.IsEmpty()) {
    std::ptrdiff_t count = qu.Count();
    size_ = (count + 4) / 4 * 4;
    head_ = 0;
    tail_ = count - 1;
    //data_ = new T[size_];
    data_ = std::make_unique<T[]>(size_);
    if (qu.head_ < qu.tail_) {
      std::copy(qu.data_.get() + qu.head_, qu.data_.get() + qu.tail_ + 1, data_.get());
    }
    else {
      std::copy(qu.data_.get() + qu.head_, qu.data_.get() + qu.size_, data_.get());
      std::copy(qu.data_.get(), qu.data_.get() + qu.tail_ + 1, data_.get() + qu.size_ - qu.head_);
    }
  }
}


template <typename T>
QueueArrT<T>& QueueArrT<T>::operator=(const QueueArrT& copy) {
  if (this != &copy) {
    std::ptrdiff_t count = copy.Count();
    Clear();
    if (!copy.IsEmpty()) {
      if (size_ < count) {
        size_ = (count + 4) / 4 * 4;
        data_ = std::make_unique<T[]>(size_);
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

template <typename T>
void QueueArrT<T>::Push(const T& val) {
  if (nullptr == data_) {
    head_ = 0;
    tail_ = 0;
    size_ = 2;
    data_ = std::make_unique<T[]>(size_);
  }
  else {
    if (head_ == (tail_ + 1) % size_) {
      auto new_data = std::make_unique<T[]>(size_ * 2);
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

template <typename T>
void QueueArrT<T>::Pop() noexcept {
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

template <typename T>
std::ptrdiff_t QueueArrT<T>::Count() const {
  if (head_ == -1 || tail_ == -1) {
    return 0;
  }

  return (tail_ - head_ + size_) % size_ + 1;
}

template <typename T>
T& QueueArrT<T>::Top() {
  if (head_ == -1) {
    throw std::logic_error("empty queue");
  }
  //return data_[head_];
  return data_[head_];
}

template <typename T>
const T& QueueArrT<T>::Top() const {
  if (head_ == -1) {
    throw std::logic_error("empty queue");
  }
  //return data_[head_];
  return data_[head_];
}

template <typename T>
T& QueueArrT<T>::Tail() {
  if (tail_ == -1) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  //return data_[tail_];
  return data_[tail_];
}

template <typename T>
bool QueueArrT<T>::IsEmpty() const noexcept {
  return head_ < 0;
}

template <typename T>
void QueueArrT<T>::Clear() noexcept {
  head_ = -1;
}

template <typename T>
QueueArrT<T>::QueueArrT(QueueArrT&& copy) noexcept {
  tail_ = copy.tail_;
  copy.tail_ = -1;
  head_ = copy.head_;
  copy.head_ = -1;
  size_ = copy.size_;
  copy.size_ = 0;
  data_ = std::move(copy.data_);
}

template <typename T>
QueueArrT<T>& QueueArrT<T>::operator=(QueueArrT&& copy) noexcept {
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

#endif