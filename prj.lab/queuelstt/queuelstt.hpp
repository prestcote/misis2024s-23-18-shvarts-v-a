#pragma once
#ifndef QUEUELSTT_HPP_HPP
#define QUEUELSTT_HPP_HPP

//#include <complex/complex.hpp>
#include <cstdlib>
#include <cstddef>
#include <stdexcept>

template <typename T>
class QueueLstT {
public:
  QueueLstT() = default;
  ~QueueLstT();
  QueueLstT(const QueueLstT&); 
  QueueLstT(QueueLstT&&) noexcept;
  QueueLstT& operator=(const QueueLstT&);
  QueueLstT& operator=(QueueLstT&&) noexcept;

  void Push(const T& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  T& Top();
  const T& Top() const;
  void Clear() noexcept;

  T& Tail();

private:
  struct Node {
    T v;
    Node* next_ = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

template <typename T>
QueueLstT<T>::QueueLstT(const QueueLstT& rhs) {
  Node* cur = rhs.head_;
  while (cur != nullptr) {
    Push(cur->v);
    cur = cur->next_;
  }
}

template <typename T>
QueueLstT<T>::~QueueLstT() {
  Clear();
}

template <typename T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT& copy) {
  if (this != &copy) {
    Clear();
    Node* cur = copy.head_;
    while (cur != nullptr) {
      Push(cur->v);
      cur = cur->next_;
    }
  }
  return *this;
}

template <typename T>
void QueueLstT<T>::Push(const T& new_element) {
  Node* new_node = new Node;
  new_node->v = new_element;
  if (head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  }
  else {
    tail_->next_ = new_node;
    tail_ = tail_->next_;
  }
}

template <typename T>
void QueueLstT<T>::Pop() noexcept {
  if (head_ != nullptr) {
    Node* cur = head_;
    head_ = head_->next_;
    delete cur;
    cur = nullptr;
  }
  if (head_ == nullptr) {
    tail_ = nullptr;
  }
}

template <typename T>
T& QueueLstT<T>::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("QueueLstT - try get top form empty queue.");
  }
  return head_->v;
}

template <typename T>
const T& QueueLstT<T>::Top() const {
  if (head_ == nullptr) {
    throw std::logic_error("QueueLstT - try get top form empty queue.");
  }
  return head_->v;
}

template <typename T>
T& QueueLstT<T>::Tail() {
  if (tail_ == nullptr) {
    throw std::logic_error("QueueLstT - try get top form empty queue.");
  }
  return tail_->v;
}

template <typename T>
bool QueueLstT<T>::IsEmpty() const noexcept {
  return (head_ == nullptr);
}

template <typename T>
void QueueLstT<T>::Clear() noexcept {
  while (head_ != nullptr) {
    Pop();
  }
}

template <typename T>
QueueLstT<T>::QueueLstT(QueueLstT&& copy) noexcept : head_(copy.head_), tail_(copy.tail_) {
  copy.head_ = nullptr;
  copy.tail_ = nullptr;
}

template <typename T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT&& copy) noexcept {
  if (this != &copy) {
    Clear();
    head_ = copy.head_;
    tail_ = copy.tail_;
    copy.head_ = nullptr;
    copy.tail_ = nullptr;
  }
  return *this;
}

#endif