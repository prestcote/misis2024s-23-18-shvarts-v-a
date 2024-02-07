#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP
#include <cstddef>
#include <complex/complex.hpp>

class StackArr {
public:
  StackArr() = default;
  StackArr(const StackArr& copy);
  ~StackArr();
  StackArr operator=(const StackArr&);

  void Push(const StackArr&);
  void Pop(const StackArr&) noexcept;
  bool IsEmpty(const StackArr&) noexcept;
  const Complex& Top(const StackArr&);

private:
  std::ptrdiff_t size_ = 0;
  Complex* data_ = 0;
  Complex* head_ = data_ + counter_;
  std::ptrdiff_t counter_ = 0;
};

#endif