#include <queuelst/queuelst.hpp>
//#include <complex/complex.hpp>
#include <stdexcept>
#include <cstdlib>

void QueueLst::Push(Complex& new_element) {
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

void QueueLst::Pop() noexcept {
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

Complex& QueueLst::Top() {
  if (head_ == nullptr) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->v;
}

const Complex& QueueLst::Top() const{
  if (head_ == nullptr) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->v;
}

Complex& QueueLst::Tail() {
  if (tail_ == nullptr) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return tail_->v;
}

bool QueueLst::IsEmpty() noexcept {
  return (head_ == nullptr);
}

void QueueLst::Clear() noexcept {
  while (head_ != nullptr) {
    Pop();
  }
}

QueueLst::~QueueLst() {
  Node* present = head_;
  while (head_ != nullptr) {
    Node* cur = head_;
    head_ = head_->next_;
    delete cur;
    cur = nullptr;
  }
  tail_ = nullptr;
}

QueueLst::QueueLst(const QueueLst& copy) {
  if (copy.head_ != nullptr) {
    Node* new_head = copy.head_;
    Node* present = copy.head_;
    Node* first_node = new Node;
    head_ = first_node;
    new_head = first_node;
    first_node->v = present->v;
    present = present->next_;
    while (present != nullptr) {
      Node* new_node = new Node;
      new_node->v = present->v;
      new_head->next_ = new_node;
      present = present->next_;
      new_head = new_head->next_;
    }
    new_head->next_ = nullptr;
    tail_ = new_head;
  }
}

QueueLst& QueueLst::operator=(const QueueLst& copy) {
  if (copy.head_ != nullptr) {
    if (head_ != nullptr) {
      Clear();
    }
    Node* new_head = copy.head_;
    Node* present = copy.head_;
    Node* first_node = new Node;
    head_ = first_node;
    new_head = first_node;
    first_node->v = present->v;
    present = present->next_;
    while (present != nullptr) {
      Node* new_node = new Node;
      new_node->v = present->v;
      new_head->next_ = new_node;
      present = present->next_;
      new_head = new_head->next_;
    }
    new_head->next_ = nullptr;
    tail_ = new_head;
  }
  return (*this);
}
