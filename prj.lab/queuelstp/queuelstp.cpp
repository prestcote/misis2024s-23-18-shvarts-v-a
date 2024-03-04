#include <queuelstp/queuelstp.hpp>

#include <stdexcept>

bool QueueLstP::IsEmpty() noexcept {
  return head_ == nullptr;
}

float& QueueLstP::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("empty queue");
  }
  return head_->value;
}

const float& QueueLstP::Top() const {
  if (head_ == nullptr) {
    throw std::logic_error("empty queue");
  }
  return head_->value;
}

void QueueLstP::Push(const float& new_element) {
  Node* new_node = new Node;
  new_node->value = new_element;
  if (head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  }
  else {
    tail_->next_ = new_node;
    tail_ = tail_->next_;
  }
}

void QueueLstP::Clear() noexcept {
  while (tail_ != nullptr) {
    Pop();
  }
}

void QueueLstP::Pop() noexcept { //its not working LMAO 
  Node* min_node = new Node{ 100000000 }; //at least not how its supposed to work
  Node* cur = head_;
  Node* prev = nullptr;
  while (cur != nullptr) {
    if (cur->value < min_node->value) {
      min_node = cur;
    }
    prev = cur;
    cur = cur->next_;
  }
  if (prev == nullptr) {
    cur = head_;
    head_ = head_->next_;
    delete cur;
  }
  else {
    prev->next_ = min_node->next_;
    delete min_node;
  }
}