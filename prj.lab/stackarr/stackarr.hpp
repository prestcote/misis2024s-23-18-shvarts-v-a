#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP
#include <cstddef>
#include <complex/complex.hpp>

class StackArr {
public:
  StackArr() = default;
  StackArr(const StackArr& copy);
  ~StackArr();
  StackArr operator=(const StackArr& copy);

  void Push(Complex& new_element);
  void Pop() noexcept;
  bool IsEmpty() noexcept;
  const Complex& Top();

  std::ptrdiff_t Size() const { return size_; }
  std::ptrdiff_t Head() const { return head_; }

private:
  std::ptrdiff_t size_ = 0;
  Complex* data_ = nullptr;
  std::ptrdiff_t head_ = -1;
};
#endif