#include <stackarrt/stackarrt.hpp>
#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

TEST_CASE("first attempt") {
  StackArrT<Complex> s;
  CHECK_EQ(s.Size(), 0);
  CHECK_EQ(s.IsEmpty(), true);
}

TEST_CASE("Push attempt") {
  StackArrT<Complex> s;
  s.Push(Complex(1, 2));
  CHECK_EQ(s.Size(), 2);
  CHECK_EQ(s.Head(), 0);
  CHECK_EQ(s.IsEmpty(), false);

  s.Push(Complex (1, 3));
  CHECK_EQ(s.Top(), Complex(1, 3));
  s.Pop();
  CHECK_EQ(s.Top(), Complex(1, 2));
  s.Pop();
  s.Pop();
  s.Pop();
  s.Pop();
  s.Pop();
}

TEST_CASE("copy ctor") {
  StackArrT<Complex> s;
  s.Push(Complex(1, 2));
  StackArrT<Complex> s2(s);
  CHECK_EQ(s.Head(), 0);
  //CHECK_EQ(s.Size(), 2);
  CHECK_EQ(s.IsEmpty(), false);
  CHECK_EQ(s.Top(), Complex(1, 2));
}

TEST_CASE("operator=") {
  StackArrT<Complex> s;
  s.Push(Complex(1, 2));
  s.Push(Complex(1, 1));
  s.Push(Complex(1, 3));
  StackArrT<Complex> s3;
  s3 = s;
  CHECK_EQ(s3.Head(), 2);
  CHECK_EQ(s3.Size(), 3);
  CHECK_EQ(s3.Top(), Complex(1, 3));
  s3.Push(Complex(1, 4));
  s3.Push(Complex(1, 5));
  s3.Push(Complex(1, 6));
  std::cout << s3.Top();
}

Complex c1(1, 2);
Complex c2(2, 3);
Complex c3(3, 4);

TEST_CASE("def ctor") {
  StackArrT<Complex> sa;
}

TEST_CASE("initlist ctor") {
  //StackArrT<Complex> sa = { c1, c2, c3 };
  StackArrT<Complex> sa;
  sa.Push(c1);
  sa.Push(c2);
  sa.Push(c3);

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());
}

TEST_CASE("copy ctor") {
  StackArrT<Complex> sa_parent;
  sa_parent.Push(c1);
  sa_parent.Push(c2);
  sa_parent.Push(c3);

  StackArrT<Complex> sa(sa_parent);

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());

  CHECK_EQ(c3, sa_parent.Top());
}

TEST_CASE("eq ctor") {
  //StackArrT<Complex> sa_parent = { c1, c2, c3 };
  StackArrT<Complex> sa_parent;
  sa_parent.Push(c1);
  sa_parent.Push(c2);
  sa_parent.Push(c3);
  StackArrT<Complex> sa = sa_parent;

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());

  CHECK_EQ(c3, sa_parent.Top());
}

TEST_CASE("empty check") {
  StackArrT<Complex> sa;
  CHECK_EQ(sa.IsEmpty(), true);

  sa.Push(c1);
  CHECK_EQ(c1, sa.Top());
  CHECK_EQ(sa.IsEmpty(), false);
  sa.Pop();

  CHECK_EQ(sa.IsEmpty(), true);
  CHECK_THROWS((void)sa.Top());
}

TEST_CASE("StackArrT<Complex> ctor") {
  StackArrT<Complex> stack;
  CHECK_EQ(stack.IsEmpty(), 1);
  StackArrT<Complex> stack_copy(stack);
  CHECK_EQ(stack_copy.IsEmpty(), 1);
}

TEST_CASE("push, pop, top, clear") {
  StackArrT<Complex> stack;
  CHECK_THROWS(void(stack.Top()));
  stack.Push(Complex(1, 2));
  CHECK_EQ(stack.IsEmpty(), 0);
  CHECK_EQ(stack.Top(), Complex(1, 2));
  stack.Pop();
  CHECK_EQ(stack.IsEmpty(), 1);
  stack.Push(Complex(1));
  stack.Clear();
  CHECK_EQ(stack.IsEmpty(), 1);
}
