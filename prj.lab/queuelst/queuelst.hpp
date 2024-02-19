#pragma once
#ifndef QUEUELST_HPP_HPP
#define QUEUELST_HPP_HPP

#include <complex/complex.hpp>
#include <cstdlib>
#include <cstddef>

class QueueLst {
public:

  QueueLst() = default;
  ~QueueLst() = default;
  QueueLst(const Complex& copy); 
  QueueLst& operator=(const Complex& copy);

  void Push(Complex& new_element);
  void Pop() noexcept;
  bool IsEmpty() noexcept;
  Complex& Top();
  const Complex& Top() const;

  Complex& Tail();

private:
  struct Node {
    Complex v;
    Node* next_ = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif