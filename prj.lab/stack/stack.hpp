#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP
#include <cstddef>

class StackArr {
public:
  StackArr() = default;
  StackArr(const StackArr& copy);
  ~StackArr() = default;
  StackArr operator=(const StackArr&);

  void Push(const StackArr&);
  void Pop() noexcept;
  void IsEmpty() noexcept;
  // const Complex& Top();

private:
  std::ptrdiff_t size_ = 0;
  float* data = 0;
  std::ptrdiff_t capacity = 0;
};

#endif