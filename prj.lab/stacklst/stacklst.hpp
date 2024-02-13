#pragma once 
#ifndef STACKLST_HPP
#define STACKLST_HPP
#include <complex/complex.hpp>
#include <cstddef>

//class Complex;

class StackLst {
public:
  StackLst() = default;
  ~StackLst();
  StackLst(const StackLst& copy);
  StackLst& operator=(const StackLst&) = default;

  void Push(const Complex& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  void Clear() noexcept;

  Complex& Top();
  const Complex& Top() const;

private:
  struct Node {
    Complex v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
};

#endif