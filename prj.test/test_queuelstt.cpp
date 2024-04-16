#include <queuelstt/queuelstt.hpp>
#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <chrono>

TEST_CASE("default ctor") {
  QueueLstT<Complex> q;
  CHECK_EQ(q.IsEmpty(), 1);
}

TEST_CASE("push method") {
  QueueLstT<Complex> q;
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

TEST_CASE("copy ctor") {
  QueueLstT<Complex> q;
  QueueLstT<Complex> q_copy(q);
  CHECK_EQ(q_copy.IsEmpty(), 1);
  q_copy.Push(Complex(1, 1));
  q_copy.Push(Complex(1, 2));
  CHECK_EQ(q_copy.Top(), Complex(1, 1));
  CHECK_EQ(q_copy.Tail(), Complex(1, 2));
  q_copy.Pop();
  CHECK_EQ(q_copy.Top(), Complex(1, 2));
  CHECK_EQ(q_copy.Tail(), Complex(1, 2));
  q_copy.Pop();
  CHECK_EQ(q_copy.IsEmpty(), 1);
}

TEST_CASE("operator=") {
  QueueLstT<Complex> q;
  QueueLstT<Complex> q_copy = q;
  CHECK_EQ(q_copy.IsEmpty(), 1);
  q_copy.Push(Complex(1, 1));
  q_copy.Push(Complex(1, 2));
  CHECK_EQ(q_copy.Top(), Complex(1, 1));
  CHECK_EQ(q_copy.Tail(), Complex(1, 2));
  q_copy.Pop();
  CHECK_EQ(q_copy.Top(), Complex(1, 2));
  CHECK_EQ(q_copy.Tail(), Complex(1, 2));
  q_copy.Pop();
  CHECK_EQ(q_copy.IsEmpty(), 1);
}

TEST_CASE("MOVE SEMANTICS") {
  Complex c1(1, 2);
  Complex c2(2, 3);
  Complex c3(3, 4);

  QueueLstT<Complex> ql_parent;
  ql_parent.Push(c3);
  ql_parent.Push(c3);
  ql_parent.Push(c3);
  ql_parent.Push(c2);
  ql_parent.Push(c1);
  QueueLstT<Complex> ql_0(ql_parent);

  auto start_1{ std::chrono::steady_clock::now() };
  QueueLstT<Complex> ql_1(ql_parent);
  auto end_1{ std::chrono::steady_clock::now() };

  auto start_2{ std::chrono::steady_clock::now() };
  QueueLstT<Complex> ql_2(std::move(ql_parent));
  auto end_2{ std::chrono::steady_clock::now() };

  ql_parent = ql_0;
  auto start_3{ std::chrono::steady_clock::now() };
  QueueLstT<Complex> ql_3 = std::move(ql_parent);
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


  CHECK(elapsed_2 + std::chrono::nanoseconds(200) < elapsed_1);
  CHECK(elapsed_3 + std::chrono::nanoseconds(200) < elapsed_1);
}