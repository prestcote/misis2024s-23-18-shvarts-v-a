#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>
#include <iostream>


void StackLst::Push(Complex& new_element) {
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

}

bool StackLst::IsEmpty() const noexcept {
  return head_ == nullptr;
}

void StackLst::Clear() noexcept {}

