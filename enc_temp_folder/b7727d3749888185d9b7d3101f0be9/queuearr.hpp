#pragma once
#ifndef QUEUEARR_HPP_HPP
#define QUEUEARR_HPP_HPP

#include "complex/complex.hpp"
#include <cstdlib>
#include <cstddef>
#include <memory>

class QueueArr {
public:
  QueueArr() = default;;
  ~QueueArr();
  QueueArr(const QueueArr& copy);
  QueueArr(QueueArr&& copy) noexcept;
  QueueArr& operator=(const QueueArr& copy);
  QueueArr& operator=(QueueArr&& copy) noexcept;

  void Push(const Complex& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  Complex& Top();
  const Complex& Top() const;
  void Clear() noexcept;

  Complex& Tail();
  std::ptrdiff_t Size() {
    return size_;
  }

private:
  std::unique_ptr<Complex[]> data_ = nullptr;
  //auto data_ = std::make_unique<Complex>(nullptr);
  //std::unique_ptr<Complex> data_ = std::make_unique<Complex>(nullptr);
  std::ptrdiff_t head_ = -1;
  std::ptrdiff_t tail_ = -1;
  std::ptrdiff_t size_ = 0;

  std::ptrdiff_t Count() const;
  std::ptrdiff_t counter = 0;
};

#endif