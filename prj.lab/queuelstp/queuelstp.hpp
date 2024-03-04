#pragma once
#ifndef QUEUELSTP_HPP_HPP
#define QUEUELSTP_HPP_HPP

#include <cstdlib>
#include <cstddef>

class QueueLstP {
public:
  QueueLstP() = default;
  QueueLstP(const QueueLstP&) = default;
  QueueLstP(QueueLstP&&) = default;
  QueueLstP& operator=(const QueueLstP&) = default;
  QueueLstP& operator=(QueueLstP&&) = default;
  ~QueueLstP() = default;

  float& Top();
  const float& Top() const;
  void Push(const float& new_element);
  void Pop() noexcept;
  bool IsEmpty() noexcept;
  void Clear() noexcept;

private:
  struct Node {
    float value;
    Node* next_ = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};


#endif