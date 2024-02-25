#include <queuelst/queuelst.hpp>
#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

TEST_CASE("default ctor") {
  QueueLst q;
  CHECK_EQ(q.IsEmpty(), 1);
}

TEST_CASE("push method") {
  QueueLst q;
  q.Push(Complex(1, 1));
  std::cout << q.Top();
  std::cout << q.Tail() << std::endl;
  q.Push(Complex(1, 2));
  std::cout << q.Top();
  std::cout << q.Tail() << std::endl;
  q.Push(Complex(1, 3));
  std::cout << q.Top();
  std::cout << q.Tail() << std::endl;
  q.Pop();
  std::cout << q.Top();
  std::cout << q.Tail() << std::endl;
  q.Pop();
  std::cout << q.Top();
  std::cout << q.Tail() << std::endl;
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  //std::cout << q.Top();
  CHECK_THROWS(std::cout << q.Top());
  CHECK_THROWS(std::cout << q.Tail());
}

TEST_CASE("copy ctor") {
  QueueLst q;
  QueueLst q_copy(q);
  CHECK_EQ(q_copy.IsEmpty(), 1);
  q_copy.Push(Complex(1, 1));
  q_copy.Push(Complex(1, 2));
  CHECK_EQ(q_copy.Top(), Complex(1, 1));
  CHECK_EQ(q_copy.Tail(), Complex(1, 2));
  q_copy.Pop();
  CHECK_EQ(q_copy.Top(), Complex(1, 2));
  CHECK_EQ(q_copy.Tail(), Complex(1, 2));
  q_copy.Pop();
  CHECK_EQ(q_copy.IsEmpty(), 1);
}

TEST_CASE("operator=") {
  QueueLst q;
  QueueLst q_copy = q;
  CHECK_EQ(q_copy.IsEmpty(), 1);
  q_copy.Push(Complex(1, 1));
  q_copy.Push(Complex(1, 2));
  CHECK_EQ(q_copy.Top(), Complex(1, 1));
  CHECK_EQ(q_copy.Tail(), Complex(1, 2));
  q_copy.Pop();
  CHECK_EQ(q_copy.Top(), Complex(1, 2));
  CHECK_EQ(q_copy.Tail(), Complex(1, 2));
  q_copy.Pop();
  CHECK_EQ(q_copy.IsEmpty(), 1);
}