#include <queuelstt/queuelstt.hpp>
#include "vector.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <chrono>

TEST_CASE_TEMPLATE("default ctor", T, int, double, std::string, Complex, Rational) {
  QueueLstT<T> q;
  CHECK_EQ(q.IsEmpty(), 1);
  CHECK_THROWS(q.Top());
}

TEST_CASE_TEMPLATE("push method", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);

  QueueLstT<T> q;
  CHECK_EQ(q.IsEmpty(), true);
  q.Push(vector[0]);
  CHECK_EQ(q.Top(), vector[0]);
  CHECK_EQ(q.Tail(), vector[0]);
  q.Push(vector[1]);
  CHECK_EQ(q.Top(), vector[0]);
  CHECK_EQ(q.Tail(), vector[1]);
  q.Push(vector[2]);
  CHECK_EQ(q.Top(), vector[0]);
  CHECK_EQ(q.Tail(), vector[2]);
  q.Pop();
  CHECK_EQ(q.Top(), vector[1]);
  CHECK_EQ(q.Tail(), vector[2]);
  q.Pop();
  CHECK_EQ(q.Top(), vector[2]);
  CHECK_EQ(q.Tail(), vector[2]);
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  CHECK_THROWS(q.Top());
  CHECK_THROWS(q.Tail());
}

TEST_CASE_TEMPLATE("copy ctor", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  
  QueueLstT<T> q;
  QueueLstT<T> q_copy(q);
  CHECK_EQ(q_copy.IsEmpty(), 1);
  q_copy.Push(vector[0]);
  q_copy.Push(vector[1]);
  CHECK_EQ(q_copy.Top(), vector[0]);
  CHECK_EQ(q_copy.Tail(), vector[1]);
  q_copy.Pop();
  CHECK_EQ(q_copy.Top(), vector[1]);
  CHECK_EQ(q_copy.Tail(), vector[1]);
  q_copy.Pop();
  CHECK_EQ(q_copy.IsEmpty(), 1);
}

TEST_CASE_TEMPLATE("operator=", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  
  QueueLstT<T> q;
  QueueLstT<T> q_copy = q;
  CHECK_EQ(q_copy.IsEmpty(), 1);
  q_copy.Push(vector[0]);
  q_copy.Push(vector[1]);
  CHECK_EQ(q_copy.Top(), vector[0]);
  CHECK_EQ(q_copy.Tail(), vector[1]);
  q_copy.Pop();
  CHECK_EQ(q_copy.Top(), vector[1]);
  CHECK_EQ(q_copy.Tail(), vector[1]);
  q_copy.Pop();
  CHECK_EQ(q_copy.IsEmpty(), 1);
}

TEST_CASE_TEMPLATE("MOVE SEMANTICS", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  T c1(vector[0]);
  T c2(vector[1]);
  T c3(vector[2]);

  QueueLstT<T> ql_parent;
  ql_parent.Push(c3);
  ql_parent.Push(c3);
  ql_parent.Push(c3);
  ql_parent.Push(c2);
  ql_parent.Push(c1);
  QueueLstT<T> ql_0(ql_parent);

  auto start_1{ std::chrono::steady_clock::now() };
  QueueLstT<T> ql_1(ql_parent);
  auto end_1{ std::chrono::steady_clock::now() };

  auto start_2{ std::chrono::steady_clock::now() };
  QueueLstT<T> ql_2(std::move(ql_parent));
  auto end_2{ std::chrono::steady_clock::now() };

  ql_parent = ql_0;
  auto start_3{ std::chrono::steady_clock::now() };
  QueueLstT<T> ql_3 = std::move(ql_parent);
  auto end_3{ std::chrono::steady_clock::now() };

  std::chrono::nanoseconds elapsed_1(end_1 - start_1);
  std::chrono::nanoseconds elapsed_2(end_2 - start_2);
  std::chrono::nanoseconds elapsed_3(end_3 - start_3);

  // std::cout << elapsed_1 << ' ' << elapsed_2 << ' ' << elapsed_3;

  CHECK_EQ(c3, ql_1.Top());
  ql_1.Pop();
  CHECK_EQ(c3, ql_1.Top());
  ql_1.Pop();
  CHECK_EQ(c3, ql_1.Top());
  ql_1.Pop();
  CHECK_EQ(c2, ql_1.Top());
  ql_1.Pop();
  CHECK_EQ(c1, ql_1.Top());
  ql_1.Pop();
  CHECK(ql_1.IsEmpty());

  //CHECK_EQ(c3, ql_2.Top());
  ql_2.Pop();
  CHECK_EQ(c3, ql_2.Top());
  ql_2.Pop();
  CHECK_EQ(c3, ql_2.Top());
  ql_2.Pop();
  CHECK_EQ(c2, ql_2.Top());
  ql_2.Pop();
  CHECK_EQ(c1, ql_2.Top());
  ql_2.Pop();
  CHECK(ql_2.IsEmpty());

  CHECK_EQ(c3, ql_3.Top());
  ql_3.Pop();
  CHECK_EQ(c3, ql_3.Top());
  ql_3.Pop();
  CHECK_EQ(c3, ql_3.Top());
  ql_3.Pop();
  CHECK_EQ(c2, ql_3.Top());
  ql_3.Pop();
  CHECK_EQ(c1, ql_3.Top());
  ql_3.Pop();
  CHECK(ql_3.IsEmpty());


  CHECK(elapsed_2 + std::chrono::nanoseconds(300) < elapsed_1);
  CHECK(elapsed_3 + std::chrono::nanoseconds(300) < elapsed_1);
}