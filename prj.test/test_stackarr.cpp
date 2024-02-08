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
  CHECK_EQ(s.Size(), 10);
  CHECK_EQ(s.Counter(), 1);
  CHECK_EQ(s.IsEmpty(), 0);
  Complex t(s.Top());
  //s.Push(Complex(1, 3));
}