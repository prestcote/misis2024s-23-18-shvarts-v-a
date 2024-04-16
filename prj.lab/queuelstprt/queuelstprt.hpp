#pragma once
#ifndef QUEUELSTPRT_HPP_HPP
#define QUEUELSTPRT_HPP_HPP

#include <cstdlib>
#include <cstddef>

template <typename T>
class QueueLstPrT {
public:
  QueueLstPrT() = default;
  QueueLstPrT(const QueueLstPrT& copy);
  QueueLstPrT(QueueLstPrT&&);
  QueueLstPrT& operator=(const QueueLstPrT& copy);
  QueueLstPrT& operator=(QueueLstPrT&&);
  ~QueueLstPrT();

  T& Top();
  const T& Top() const;
  void Push(const T& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  void Clear() noexcept;

  void Print();

private:
  struct Node {
    T value;
    Node* next_ = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

template <typename T>
QueueLstPrT<T>::~QueueLstPrT() {
  Node* cur = head_;
  while (head_ != nullptr) {
    cur = head_;
    head_ = head_->next_;
    delete cur;
  }
  cur = nullptr;
}

template <typename T>
QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT& copy) {
  Node* temp = copy.head_;
  while (temp != nullptr) {
    Push(temp->value);
    temp = temp->next_;
  }
}

template <typename T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(const QueueLstPrT& copy) {
  if (this != &copy) {
    Clear();
    Node* temp = copy.head_;
    while (temp != nullptr) {
      Push(temp->value);
      temp = temp->next_;
    }
  }
  return *this;
}

template <typename T>
bool QueueLstPrT<T>::IsEmpty() const noexcept {
  return head_ == nullptr;
}

template <typename T>
T& QueueLstPrT<T>::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("empty queue");
  }
  return head_->value;
}

template <typename T>
const T& QueueLstPrT<T>::Top() const {
  if (head_ == nullptr) {
    throw std::logic_error("empty queue");
  }
  return head_->value;
}

template <typename T>
void QueueLstPrT<T>::Push(const T& new_element) {
  Node* new_node = new Node;
  new_node->value = new_element;
  Node* cur = head_;
  Node* prev = nullptr;
  if (head_ != nullptr) {
    while (cur != nullptr && new_element > cur->value) {
      prev = cur;
      cur = cur->next_;
    }
    if (prev != nullptr) {
      prev->next_ = new_node;
      new_node->next_ = cur;
    }
    else {
      new_node->next_ = head_;
      head_ = new_node;
    }
  }
  else {
    head_ = new_node;
    tail_ = new_node;
  }
}

template <typename T>
void QueueLstPrT<T>::Clear() noexcept {
  while (tail_ != nullptr) {
    Pop();
  }
}

template <typename T>
void QueueLstPrT<T>::Pop() noexcept {
  if (head_ != nullptr) {
    Node* cur = head_;
    head_ = head_->next_;
    delete cur;
  }
  else {
    tail_ = nullptr;
  }
}

template <typename T>
void QueueLstPrT<T>::Print() {
  if (head_ != nullptr) {
    Node* cur = head_;
    while (cur != nullptr) {
      std::cout << cur->value << ' ';
      cur = cur->next_;
    }
  }
  else {
    std::cout << "empty";
  }
  std::cout << std::endl;
}

template <typename T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT&& copy) {
  head_ = copy.head_;
  tail_ = copy.tail_;
  copy.head_ = nullptr;
  copy.tail_ = nullptr;
}

template <typename T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(QueueLstPrT&& copy) {
  if (this != &copy) {
    Clear();
    std::swap(head_, copy.head_);
    std::swap(tail_, copy.tail_);
  }
  return *this;
}

#endif