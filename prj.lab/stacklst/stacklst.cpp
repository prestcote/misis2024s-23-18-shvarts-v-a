#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>
#include <iostream>


StackLst::~StackLst() {
  Node* present = head_;
  while (head_ != nullptr) {
    present = head_;
    head_ = head_->next;
    delete present;
  }
}
/*
StackLst::StackLst(const StackLst& copy) {
  Node* node_copy = copy.head_;
  if (copy.head_ != nullptr) {
    Node* present = head_;
    while (present->next != nullptr) {
      copy.Push(present->v);
      present = present->next;
    }
    present->next = nullptr;
  }
}
*/
void StackLst::Push(const Complex& new_element) {
  Node* new_node = new Node;
  new_node->v = new_element;
  if (head_ == nullptr) {
    head_ = new_node;
  }
  else {
    Node* present = head_;
    while (present->next != nullptr) {
      present = present->next;
    }
    present->next = new_node;
  }
}

void StackLst::Pop() noexcept {
  if (head_ != nullptr) {
    Node* present = head_;
    int counter = 0;
    while (present->next != nullptr) {
      counter += 1;
      present = present->next;
    }
    //present = present->next;
    std::cout << present->v; 
    Node* delete_this = head_;
    for (int i = 0; i < counter-1; i++) {
      delete_this = delete_this->next;
    }
    delete_this->next = nullptr;
  }
}

bool StackLst::IsEmpty() const noexcept {
  return head_ == nullptr;
}

void StackLst::Clear() noexcept {}

Complex& StackLst::Top() {
  Node* present = head_;
  while (present->next != nullptr) {
    present = present->next;
  }
  //present = present->next;
  return present->v;
}

const Complex& StackLst::Top() const {
  Node* present = head_;
  while (present->next != nullptr) {
    present = present->next;
  }
  //present = present->next;
  return present->v;
}

