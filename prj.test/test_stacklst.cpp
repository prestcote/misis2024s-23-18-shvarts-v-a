#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

TEST_CASE("were sooo down") {
  StackLst s;
  s.Push(Complex(1, 2));
  s.Push(Complex(1, 3));
  s.Push(Complex(1, 4));
  s.Push(Complex(1, 5));
  s.Push(Complex(1, 6));
  s.Pop();
  CHECK_EQ(s.IsEmpty(), 0);
  //CHECK_EQ(s.Top(), Complex(1, 6));
  //s.Pop();
  StackLst s1(s);
  s1.Pop();
  s1.Pop();
  std::cout << s1.Top();
  //std::cout << s.Top();
  //std::cout << s.Head();
  StackLst s2;
  s2 = s1;
  std::cout << s2.Top();
  StackLst s3(s1);
  s3.Push(Complex(1, 10));
  s3.Push(Complex(1, 11));
  s2 = s3;
  std::cout << s2.Top();
  
  s.Clear();
  CHECK_THROWS(s.Top());
  CHECK_EQ(s.IsEmpty(), 1);
}