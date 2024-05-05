#pragma once
#ifndef QUEUELSTPR_HPP_HPP
#define QUEUELSTPR_HPP_HPP

#include <cstdlib>
#include <cstddef>

class QueueLstPr {
public:
  QueueLstPr() = default;
  QueueLstPr(const QueueLstPr& copy);
  QueueLstPr(QueueLstPr&&) noexcept;
  QueueLstPr& operator=(const QueueLstPr& copy);
  QueueLstPr& operator=(QueueLstPr&&) noexcept;
  ~QueueLstPr();

  float& Top();
  const float& Top() const;
  void Push(const float& new_element);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  void Clear() noexcept;

  void Print();

private:
  struct Node {
    float value;
    Node* next_ = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};


#endif