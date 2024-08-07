#pragma once
#ifndef QUEUELST_HPP_HPP
#define QUEUELST_HPP_HPP

#include <complex/complex.hpp>
#include <cstdlib>
#include <cstddef>

class QueueLst {
public:

  QueueLst() = default;
  ~QueueLst();
  QueueLst(const QueueLst&); 
  QueueLst(QueueLst&&) noexcept;
  QueueLst& operator=(const QueueLst&);
  QueueLst& operator=(QueueLst&&) noexcept;

  void Push(const Complex& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  Complex& Top();
  const Complex& Top() const;
  void Clear() noexcept;

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