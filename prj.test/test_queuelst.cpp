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