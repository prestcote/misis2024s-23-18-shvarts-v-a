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
  if (head_ != nullptr) {
    Node* present = head_;
    while (present->next != nullptr) {
      Push(present->v);
      present = present->next;
    }
    present->next = nullptr;
  }
}*/
StackLst::StackLst(const StackLst& copy) {
  Node* new_head = copy.head_;
  Node* present = copy.head_;
  //new_head->v = present->v;
  while (present->next != nullptr) {
    Node* new_node = new Node;
    new_node->v = present->next->v;
    new_head->next = new_node;
    present = present->next;
    new_head = new_head->next;
  }
  new_head->next = nullptr;
}

/*
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
*/
void StackLst::Push(const Complex& new_element) {
  Node* new_node = new Node;
  new_node->next = head_;
  new_node->v = new_element;
  head_ = new_node;
}
/*
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
}*/

void StackLst::Pop() noexcept{
  if (head_ != nullptr) {
    Node* delete_node = head_;
    head_ = head_->next;
    delete delete_node;
    delete_node = nullptr;
  }
}

bool StackLst::IsEmpty() const noexcept {
  return head_ == nullptr;
}

void StackLst::Clear() noexcept {}
/*
Complex& StackLst::Top() {
  Node* present = head_;
  while (present->next != nullptr) {
    present = present->next;
  }
  //present = present->next;
  return present->v;
} */
Complex& StackLst::Top() {
  if (head_ != nullptr) {
    return head_->v;
  }
}

const Complex& StackLst::Top() const {
  if (head_ != nullptr) {
    return head_->v;
  }
}

