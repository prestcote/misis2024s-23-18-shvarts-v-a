#include <stackarrt/stackarrt.hpp>
#include "vector.hpp"
//#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

TEST_CASE_TEMPLATE("first attempt", T, int, std::string, Complex, Rational) {
  StackArrT<T> s;
  CHECK_EQ(s.Size(), 0);
  CHECK_EQ(s.IsEmpty(), true);
}

TEST_CASE_TEMPLATE("Push attempt", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();
  
  StackArrT<T> s;
  s.Push(test[0]);
  CHECK_EQ(s.Size(), 2);
  CHECK_EQ(s.Head(), 0);
  CHECK_EQ(s.IsEmpty(), false);

  s.Push(test[1]);
  CHECK_EQ(s.Top(), test[1]);
  s.Pop();
  CHECK_EQ(s.Top(), test[0]);
  s.Pop();
  s.Pop();
  s.Pop();
  s.Pop();
  s.Pop();
}

TEST_CASE_TEMPLATE("copy ctor", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();
  
  StackArrT<T> s;
  s.Push(test[0]);
  StackArrT<T> s2(s);
  CHECK_EQ(s.Head(), 0);
  //CHECK_EQ(s.Size(), 2);
  CHECK_EQ(s.IsEmpty(), false);
  CHECK_EQ(s.Top(), test[0]);
}

TEST_CASE_TEMPLATE("operator=", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();
  
  StackArrT<T> s;
  for (int i = 0; i < 3; i++) {
    s.Push(test[i]);
    CHECK_EQ(s.Top(), test[i]);
  }
  StackArrT<T> s3;
  s3 = s;
  CHECK_EQ(s3.Head(), 2);
  CHECK_EQ(s3.Size(), 3);
  CHECK_EQ(s3.Top(), test[2]);
  s3.Push(test[3]);
  s3.Push(test[4]);
  CHECK_EQ(s3.Top(), test[4]);
}


TEST_CASE_TEMPLATE("def ctor", T, int, std::string, Complex, Rational) {
  StackArrT<T> sa;
}

TEST_CASE_TEMPLATE("initlist ctor", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();
  T c1 = test[0];
  T c2 = test[1];
  T c3 = test[2];

  StackArrT<T> sa;
  sa.Push(c1);
  sa.Push(c2);
  sa.Push(c3);

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());
}

TEST_CASE_TEMPLATE("copy ctor", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();
  T c1 = test[0];
  T c2 = test[1];
  T c3 = test[2];

  StackArrT<T> sa_parent;
  sa_parent.Push(c1);
  sa_parent.Push(c2);
  sa_parent.Push(c3);

  StackArrT<T> sa(sa_parent);

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());

  CHECK_EQ(c3, sa_parent.Top());
}

TEST_CASE_TEMPLATE("eq ctor", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();
  T c1 = test[0];
  T c2 = test[1];
  T c3 = test[2];

  StackArrT<T> sa_parent;
  sa_parent.Push(c1);
  sa_parent.Push(c2);
  sa_parent.Push(c3);
  StackArrT<T> sa = sa_parent;

  CHECK_EQ(c3, sa.Top());
  sa.Pop();
  CHECK_EQ(c2, sa.Top());
  sa.Pop();
  CHECK_EQ(c1, sa.Top());

  CHECK_EQ(c3, sa_parent.Top());
}

TEST_CASE_TEMPLATE("empty check", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();
  T c1 = test[0];
  T c2 = test[1];
  T c3 = test[2];

  StackArrT<T> sa;
  CHECK_EQ(sa.IsEmpty(), true);

  sa.Push(c1);
  CHECK_EQ(c1, sa.Top());
  CHECK_EQ(sa.IsEmpty(), false);
  sa.Pop();

  CHECK_EQ(sa.IsEmpty(), true);
  CHECK_THROWS((void)sa.Top());
}

TEST_CASE_TEMPLATE("StackArrT<T> ctor", T, int, std::string, Complex, Rational) {

  StackArrT<T> stack;
  CHECK_EQ(stack.IsEmpty(), 1);
  StackArrT<T> stack_copy(stack);
  CHECK_EQ(stack_copy.IsEmpty(), 1);
}

TEST_CASE_TEMPLATE("push, pop, top, clear", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();
  T c1 = test[0];
  T c2 = test[1];
  T c3 = test[2];

  StackArrT<T> stack;
  CHECK_THROWS(void(stack.Top()));
  stack.Push(c1);
  CHECK_EQ(stack.IsEmpty(), 0);
  CHECK_EQ(stack.Top(), c1);
  stack.Pop();
  CHECK_EQ(stack.IsEmpty(), 1);
  stack.Push(c2);
  stack.Clear();
  CHECK_EQ(stack.IsEmpty(), 1);
}
