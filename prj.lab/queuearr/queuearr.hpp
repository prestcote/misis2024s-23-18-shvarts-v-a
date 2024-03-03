#pragma once
#ifndef QUEUEARR_HPP_HPP
#define QUEUEARR_HPP_HPP

#include <complex/complex.hpp>
#include <cstdlib>
#include <cstddef>

class QueueArr {
public:
  QueueArr() = default;
  ~QueueArr();
  QueueArr(const QueueArr& copy);
  QueueArr(QueueArr&&) = default;
  QueueArr& operator=(const QueueArr&) = default;
  QueueArr& operator=(QueueArr&&) = default;

  void Push(const Complex& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  Complex& Top();
  const Complex& Top() const;
  void Clear() noexcept;

  Complex& Tail();

private:
  Complex* data_ = nullptr;
  std::ptrdiff_t head_ = -1;
  std::ptrdiff_t tail_ = -1;
  std::ptrdiff_t size_ = 0;

  std::ptrdiff_t Count() const;

};

#endif