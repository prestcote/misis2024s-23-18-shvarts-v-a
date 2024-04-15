#include <stacklstt/stacklstt.hpp>
#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

TEST_CASE("compilation check") {
  CHECK(0 == 0);
  StackLstT<Complex> t;
}
TEST_CASE("were sooo down") {
  StackLstT<Complex> s;
  s.Push(Complex(1, 2));
  s.Push(Complex(1, 3));
  s.Push(Complex(1, 4));
  s.Push(Complex(1, 5));
  s.Push(Complex(1, 6));
  s.Pop();
  CHECK_EQ(s.IsEmpty(), 0);
  //CHECK_EQ(s.Top(), Complex(1, 6));
  //s.Pop();
  StackLstT<Complex> s1(s);
  s1.Pop();
  s1.Pop();
  std::cout << s1.Top();
  //std::cout << s.Top();
  //std::cout << s.Head();
  StackLstT<Complex> s2;
  s2 = s1;
  std::cout << s2.Top();
  StackLstT<Complex> s3(s1);
  s3.Push(Complex(1, 10));
  s3.Push(Complex(1, 11));
  s2 = s3;
  std::cout << s2.Top();

  s.Clear();
  CHECK_THROWS(s.Top());
  CHECK_EQ(s.IsEmpty(), 1);
}

Complex c1(1, 2);
Complex c2(2, 3);
Complex c3(3, 4);

TEST_CASE("def ctor") {
  StackLstT<Complex> sa;
}

TEST_CASE("copy ctor") {
  //StackArr sa_parent = { c1, c2, c3 };
  StackLstT<Complex> sa_parent;
  sa_parent.Push(c1);
  sa_parent.Push(c2);
  sa_parent.Push(c3);
  //StackArr sa(sa_parent);
  StackLstT<Complex> sa;
  sa.Push(Complex(7, 8));
  sa = sa_parent;

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());

  CHECK_EQ(c3, sa_parent.Top());
}

TEST_CASE("eq ctor") {
  //StackArr sa_parent = { c1, c2, c3 };
  StackLstT<Complex> sa_parent;
  sa_parent.Push(c1);
  sa_parent.Push(c2);
  sa_parent.Push(c3);
  StackLstT<Complex> sa = sa_parent;

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());

  CHECK_EQ(c3, sa_parent.Top());
}

TEST_CASE("empty check") {
  StackLstT<Complex> sa;
  CHECK_EQ(sa.IsEmpty(), true);

  sa.Push(c1);
  CHECK_EQ(c1, sa.Top());
  CHECK_EQ(sa.IsEmpty(), false);
  sa.Pop();

  CHECK_EQ(sa.IsEmpty(), true);
  CHECK_THROWS(sa.Top());
}

TEST_CASE("stacklst ctor") {
  StackLstT<Complex> stack;
  CHECK_EQ(stack.IsEmpty(), 1);
  StackLstT<Complex> stack_copy(stack);
  CHECK_EQ(stack_copy.IsEmpty(), 1);
  stack_copy.Push(Complex(1, 2));
  StackLstT<Complex> eq_copy;
  eq_copy = stack;
  CHECK_EQ(eq_copy.IsEmpty(), 1);
}

TEST_CASE("push, pop, top, clear") {
  StackLstT<Complex> stack;
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

TEST_CASE("i think the problem should be in copy ctor or operator=") {
  StackLstT<Complex> a;
  CHECK_EQ(a.IsEmpty(), true);
  StackLstT<Complex> b(a);
  CHECK_EQ(b.IsEmpty(), true);
  StackLstT<Complex> c = a;
  CHECK_EQ(c.IsEmpty(), true);
  c.Push(Complex(1, 0));
  c.Push(Complex(1, 1));
  c = a;
  CHECK_EQ(c.IsEmpty(), true);
}

TYPE_TO_STRING_AS("SHORT!!!", short);
//TYPE_TO_STRING_AS("complex??????", Complex);

TEST_CASE_TEMPLATE("signed integers stuff", T, int, short, Complex) {
  StackLstT<T> s;
  s.Push(T(1));
  s.Push(T(2));
  s.Push(T(3));
  s.Push(T(4));
  s.Push(T(5));
  s.Pop();
  CHECK_EQ(s.IsEmpty(), 0);
  //CHECK_EQ(s.Top(), Complex(1, 6));
  //s.Pop();
  StackLstT<T> s1(s);
  s1.Pop();
  s1.Pop();
  std::cout << s1.Top();
  //std::cout << s.Top();
  //std::cout << s.Head();
  StackLstT<T> s2;
  s2 = s1;
  std::cout << s2.Top();
  StackLstT<T> s3(s1);
  s3.Push(T(10));
  s3.Push(T(11));
  s2 = s3;
  std::cout << s2.Top();

  s.Clear();
  CHECK_THROWS(s.Top());
  CHECK_EQ(s.IsEmpty(), 1);
} 

TEST_CASE_TEMPLATE("copy ctor", T, int, short, Complex) {
  T c1 = T(1);
  T c2 = T(2);
  T c3 = T(3);
  StackLstT<T> sa_parent;
  sa_parent.Push(c1);
  sa_parent.Push(c2);
  sa_parent.Push(c3);
  //StackArr sa(sa_parent);
  StackLstT<T> sa;
  sa.Push(T(7));
  sa = sa_parent;

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());
  CHECK_EQ(c3, sa_parent.Top());
}



