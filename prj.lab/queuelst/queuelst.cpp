#include <queuelst/queuelst.hpp>
#include <complex/complex.hpp>
#include <stdexcept>

void QueueLst::Push(Complex& new_element) {
  Node* new_node = new Node;
  new_node->v = new_element;
  if (head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  }
  else if (head_->next_ == nullptr) {
    tail_ = new_node;
    head_->next_ = tail_;
  }
  else {
    tail_->next_ = new_node;
    tail_ = new_node;
  }
}

void QueueLst::Pop() noexcept {
  if (head_ != nullptr && tail_ != nullptr) {
    if (head_ != tail_) {
      Node* cur = new Node;
      cur = head_;
      head_ = head_->next_;
      delete cur;
      cur = nullptr;
    }
    else if (head_ == tail_) {
      Node* curr = new Node;
      //curr = head_;
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
      //curr = nullptr;
    }
  }
}

Complex& QueueLst::Top() {
  if (head_ == nullptr) {
    throw std::exception("stack underflow");
  }
  return head_->v;
}

Complex& QueueLst::Tail() {
  if (tail_ == nullptr) {
    throw std::exception("stack underflow");
  }
  return tail_->v;
}

bool QueueLst::IsEmpty() noexcept {
  return (head_ == nullptr);
}

