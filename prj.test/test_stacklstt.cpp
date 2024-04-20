#include <stacklstt/stacklstt.hpp>
//#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "vector.hpp"

#include <iostream>
#include <vector>
#include <string>

TEST_CASE_TEMPLATE("push & pop", T, int, std::string, Complex, Rational) {
  std::vector <T> test = make_vector<T>();
  StackLstT<T> one;
  for (int i = 0; i < test.size(); i++) {
    one.Push(test[i]);
    CHECK(one.Top() == test[i]);
    //std::cout << test[i] << std::endl;
  }
  CHECK(one.Top() == test[test.size() - 1]);
  for (int i = test.size() - 1; i >= 0; i--) {
    CHECK(one.Top() == test[i]);
    one.Pop();
  }
  CHECK(one.IsEmpty());
}

TEST_CASE_TEMPLATE("copy ctor", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();

  StackLstT<T> sa_parent;
  for (int i = 0; i < test.size(); i++) {
    sa_parent.Push(test[i]);
    CHECK(sa_parent.Top() == test[i]);
  }
  StackLstT<T> sa;
  //sa.Push(test[test.size() - 1]);
  sa = sa_parent;

  for (int i = test.size() - 1; i >= 0; i--) {
    CHECK_EQ(sa.Head(), test[i]);
    //std::cout << sa.Head() << ' ' << test[i] << std::endl;
    sa.Pop();
  }
  CHECK_EQ(test[test.size() - 1], sa_parent.Top());
}

TEST_CASE_TEMPLATE("eq ctor", T, int, std::string, Complex, Rational) {
  //StackArr sa_parent = { c1, c2, c3 };
  std::vector<T> test = make_vector<T>();
  StackLstT<T> sa_parent;
  for (int i = 0; i < test.size(); i++) {
    sa_parent.Push(test[i]);
  }
  StackLstT<T> sa = sa_parent;
  for (int i = test.size() - 1; i >= 0; i--) {
    CHECK_EQ(test[i], sa.Top());
    sa.Pop();
  }
}

TEST_CASE_TEMPLATE("empty check", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();

  StackLstT<T> sa;
  CHECK_EQ(sa.IsEmpty(), true);

  sa.Push(test[0]);
  CHECK_EQ(test[0], sa.Top());
  CHECK_EQ(sa.IsEmpty(), false);
  sa.Pop();

  CHECK_EQ(sa.IsEmpty(), true);
  CHECK_THROWS(sa.Top());
}

TEST_CASE_TEMPLATE("stacklst ctor", T, int, std::string, Complex, Rational) {
  std::vector<T> test = make_vector<T>();

  StackLstT<T> stack;
  CHECK_EQ(stack.IsEmpty(), 1);
  StackLstT<T> stack_copy(stack);
  CHECK_EQ(stack_copy.IsEmpty(), 1);
  stack_copy.Push(test[0]);
  StackLstT<T> eq_copy;
  eq_copy = stack;
  CHECK_EQ(eq_copy.IsEmpty(), 1);
}

TEST_CASE_TEMPLATE("push, pop, top, clear", T, int, std::string, Complex, Rational) {
  std::vector <T> test = make_vector<T>();

  StackLstT<T> stack;
  CHECK_THROWS(void(stack.Top()));
  stack.Push(test[0]);
  CHECK_EQ(stack.IsEmpty(), 0);
  CHECK_EQ(stack.Top(), test[0]);
  stack.Pop();
  CHECK_EQ(stack.IsEmpty(), 1);
  stack.Push(test[1]);
  stack.Clear();
  CHECK_EQ(stack.IsEmpty(), 1);
}

TEST_CASE_TEMPLATE("i think the problem should be in copy ctor or operator=", T, int, std::string, Complex, Rational) {
  std::vector <T> test = make_vector<T>();
  
  StackLstT<T> a;
  CHECK_EQ(a.IsEmpty(), true);
  StackLstT<T> b(a);
  CHECK_EQ(b.IsEmpty(), true);
  StackLstT<T> c = a;
  CHECK_EQ(c.IsEmpty(), true);
  c.Push(test[0]);
  c.Push(test[1]);
  c = a;
  CHECK_EQ(c.IsEmpty(), true);
}



