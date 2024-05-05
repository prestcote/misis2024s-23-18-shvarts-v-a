#pragma once 
#ifndef STACKLSTT_HPP_HPP
#define STACKLSTT_HPP_HPP

//#include <complex/complex.hpp>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class StackLstT {
public:
  //using T = Complex;
  
  StackLstT();
  ~StackLstT();
  
  StackLstT(const StackLstT& copy);
  StackLstT(StackLstT&& copy) noexcept;
  
  StackLstT& operator=(const StackLstT& copy);
  StackLstT& operator=(StackLstT&& copy) noexcept;
  
  void Push(const T& new_element);
  void Pop() noexcept;
  
  bool IsEmpty() const noexcept;
  void Clear() noexcept;

  T& Top();

  const T& Top() const;

  T& Head() {
    return head_->v;
  }
  
private:
  struct Node {
    T v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
  
};

template <typename T>
StackLstT<T>::StackLstT() : head_(nullptr) {};

template<typename T>
StackLstT<T>::~StackLstT() {
  Node* present = head_;
  while (head_ != nullptr) {
    present = head_;
    head_ = head_->next;
    delete present;
  }
}

template <typename T>
StackLstT<T>:: StackLstT(const StackLstT& copy) {
  if (copy.head_ != nullptr) {
    Node* new_head = copy.head_;
    Node* present = copy.head_;
    Node* first_node = new Node;
    head_ = first_node;
    new_head = first_node;
    first_node->v = present->v;
    present = present->next;
    while (present != nullptr) {
      Node* new_node = new Node;
      new_node->v = present->v;
      new_head->next = new_node;
      present = present->next;
      new_head = new_head->next;
    }
    new_head->next = nullptr;
  }
}

template <typename T>
StackLstT<T>::StackLstT(StackLstT&& copy) noexcept {
  head_ = copy.head_;
  copy.head_ = nullptr;
}

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT& copy) {
  if (head_ != nullptr) {
    Clear();
  }
  if (copy.head_ != nullptr) {
    Node* new_head = copy.head_;
    Node* present = copy.head_;
    Node* first_node = new Node;
    head_ = first_node;
    new_head = first_node;
    first_node->v = present->v;
    present = present->next;
    while (present != nullptr) {
      Node* new_node = new Node;
      new_node->v = present->v;
      new_head->next = new_node;
      present = present->next;
      new_head = new_head->next;
    }
    new_head->next = nullptr;
  }
  return (*this);
}

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(StackLstT&& copy) noexcept {
  if (this != &copy) {
    Clear();
    head_ = copy.head_;
    copy.head_ = nullptr;
  }
  return *this;
}

template <typename T>
void StackLstT<T>::Push(const T& new_element) {
  Node* new_node = new Node;
  new_node->next = head_;
  new_node->v = new_element;
  head_ = new_node;
}

template <typename T>
void StackLstT<T>::Pop() noexcept {
  if (head_ != nullptr) {
    Node* delete_node = head_;
    head_ = head_->next;
    delete delete_node;
    delete_node = nullptr;
  }
}

template <typename T>
bool StackLstT<T>::IsEmpty() const noexcept { return (head_ == nullptr); }

template <typename T>
void StackLstT<T>::Clear() noexcept {
  while (head_ != nullptr) {
    Pop();
  }
}

template <typename T>
T& StackLstT<T>::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("StackLstT - try get top form empty stack.");
  }
  return head_->v;
}

template <typename T>
const T& StackLstT<T>::Top() const {
  if (head_ == nullptr) {
    throw std::logic_error("StackLstT - try get top form empty stack.");
  }
  return head_->v;
}

#endif