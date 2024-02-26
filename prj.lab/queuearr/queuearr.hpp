#pragma once
#ifndef QUEUEARR_HPP_HPP
#define QUEUEARR_HPP_HPP

#include <complex/complex.hpp>

class QueueArr {
public:
  QueueArr() = default;
  ~QueueArr() = default;
  QueueArr(const QueueArr&) = default;
  QueueArr& operator=(const QueueArr&) = default;

  void Push(const Complex& new_element);
  void Pop() noexcept;
  bool IsEmpty() noexcept;
  Complex& Top();
  const Complex& Top() const;
  void Clear() noexcept;

private:
  Complex* data_ = nullptr;
  std::ptrdiff_t head_ = -1;
  std::ptrdiff_t tail_ = -1;
  std::ptrdiff_t size_ = 0;

};

#endif