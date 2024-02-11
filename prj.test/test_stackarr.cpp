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
  CHECK_EQ(s.Size(), 15);
  CHECK_EQ(s.Head(), 0);
  CHECK_EQ(s.IsEmpty(), 0);

  s.Push(Complex (1, 3));
  CHECK_EQ(s.Top(), Complex(1, 3));
  s.Pop();
  CHECK_EQ(s.Top(), Complex(1, 2));
}

TEST_CASE("copy ctor") {
  StackArr s;
  s.Push(Complex(1, 2));
  StackArr s2(s);
  CHECK_EQ(s.Head(), 0);
  CHECK_EQ(s.Size(), 15);
  CHECK_EQ(s.IsEmpty(), 0);
  CHECK_EQ(s.Top(), Complex(1, 2));
}

TEST_CASE("operator=") {
  StackArr s;
  s.Push(Complex(1, 2));
  StackArr s3;
  s3 = s;
  CHECK_EQ(s3.Head(), 0);
  CHECK_EQ(s3.Size(), 15);
  CHECK_EQ(s3.Top(), Complex(1, 2));
  s3.Push(Complex(1, 4));
}