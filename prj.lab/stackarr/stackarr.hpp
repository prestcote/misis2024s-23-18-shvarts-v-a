#pragma once
#ifndef STACKARR_STACKARR_HPP
#define STACKARR_STACKARR_HPP

#include <complex/complex.hpp>
#include <cstddef>
#include <cstdlib>

class StackArr {
public:
  StackArr() = default;
  StackArr(const StackArr& copy);
  StackArr(StackArr&& copy) noexcept;
  ~StackArr();
  StackArr& operator=(const StackArr& copy);
  StackArr& operator=(StackArr&& copy) noexcept;

  void Push(const Complex& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;

  Complex& Top();
  const Complex& Top() const;

  void Clear() noexcept;

  std::ptrdiff_t Size() const { return size_; }
  std::ptrdiff_t Head() const { return head_; }

private:
  std::ptrdiff_t size_ = 0;
  Complex* data_ = nullptr;
  std::ptrdiff_t head_ = -1;
};
#endif