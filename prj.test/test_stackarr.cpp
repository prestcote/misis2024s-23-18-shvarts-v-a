#include <stackarr/stackarr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

TEST_CASE("first attempt") {
  StackArr s;
  CHECK_EQ(s.Size(), 0);
  CHECK_EQ(s.IsEmpty(), 1);
}

TEST_CASE("Push attempt") {
  StackArr s;
  s.Push(Complex(1, 2));
  CHECK_EQ(s.Size(), 12);
  CHECK_EQ(s.Head(), 0);
  CHECK_EQ(s.IsEmpty(), 0);
  //StackArr s2(s);
  Complex t(1, 3);
  s.Push(Complex (1, 2));
  //StackArr s1(s);
  //std::cout << s1.Data();
}