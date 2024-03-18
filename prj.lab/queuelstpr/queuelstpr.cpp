#include <queuelstpr/queuelstpr.hpp>

#include <iostream>
#include <stdexcept>


QueueLstPr::~QueueLstPr() {
  Node* cur = head_;
  while (head_ != nullptr) {
    cur = head_;
    head_ = head_->next_;
    delete cur;
  }
  cur = nullptr;
}

QueueLstPr::QueueLstPr(const QueueLstPr& copy) {
  head_ = nullptr;
  Node* temp = copy.head_;
  while (temp != nullptr) {
    Push(temp->value);
    temp = temp->next_;
  }
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& copy) {
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

bool QueueLstPr::IsEmpty() noexcept {
  return head_ == nullptr;
}

float& QueueLstPr::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("empty queue");
  }
  return head_->value;
}

const float& QueueLstPr::Top() const {
  if (head_ == nullptr) {
    throw std::logic_error("empty queue");
  }
  return head_->value;
}

void QueueLstPr::Push(const float& new_element) {
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
  }
}

void QueueLstPr::Clear() noexcept {
  while (tail_ != nullptr) {
    Pop();
  }
}

void QueueLstPr::Pop() noexcept {
  Node* cur = head_;
  head_ = head_->next_;
  delete cur;
}

void QueueLstPr::Print() {
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

QueueLstPr::QueueLstPr(QueueLstPr&& copy) {
  head_ = copy.head_;
  tail_ = copy.tail_;
  copy.head_ = nullptr;
  copy.tail_ = nullptr;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& copy) {
  if (this != &copy) {
    Clear();
    std::swap(head_, copy.head_);
    std::swap(tail_, copy.tail_);
  }
  return *this;
}