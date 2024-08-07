#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>

#include <iostream>
#include <stdexcept>


StackLst::~StackLst() {
  Node* present = head_;
  while (head_ != nullptr) {
    present = head_;
    head_ = head_->next;
    delete present;
  }
}

StackLst::StackLst(const StackLst& copy) {
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

StackLst& StackLst::operator=(const StackLst& copy) {
  if (this != &copy) {
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
  }
  return (*this);
}

void StackLst::Clear() noexcept{
  while (head_ != nullptr) {
    Pop();
  }
}

void StackLst::Push(const Complex& new_element) {
  Node* new_node = new Node;
  new_node->next = head_;
  new_node->v = new_element;
  head_ = new_node;
}

void StackLst::Pop() noexcept{
  if (head_ != nullptr) {
    Node* delete_node = head_;
    head_ = head_->next;
    delete delete_node;
    delete_node = nullptr;
  }
}

bool StackLst::IsEmpty() const noexcept {
  return (head_ == nullptr);
}

Complex& StackLst::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("StackLst - try get top form empty stack.");
  }
  return head_->v;
}

const Complex& StackLst::Top() const {
  if (head_ == nullptr) {
    throw std::logic_error("StackLst - try get top form empty stack.");
  }
  return head_->v;
}

StackLst::StackLst(StackLst&& copy) noexcept{
  head_ = copy.head_;
  copy.head_ = nullptr;
}

StackLst& StackLst::operator=(StackLst&& copy) noexcept {
  if (this != &copy) {
    Clear();
    head_ = copy.head_;
    copy.head_ = nullptr;
  }
  return *this;
}

