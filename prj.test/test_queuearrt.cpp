#include <queuearrt/queuearrt.hpp>
#include "vector.hpp"
//#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE_TEMPLATE("one more time", T, int, double, std::string, Complex, Rational) {
  QueueArrT<T> q;
  CHECK(q.IsEmpty() == true);
  CHECK(q.Size() == 0);
}

TEST_CASE_TEMPLATE("wellllll", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  
  QueueArrT<T> s;
  CHECK(s.IsEmpty() == true);
  CHECK_THROWS(s.Top());
  for (int i = 0; i < vector.size(); i++) {
    s.Push(vector[i]);
    CHECK(s.Top() == vector[0]);
    CHECK(s.Tail() == vector[i]);
  }
  for (int i = vector.size() - 1; i >= 0; i--) {
    //std::cout << vector[vector.size() - 1 - i] << ' ' << s.Top() << std::endl;
    CHECK_EQ(s.Top(), vector[vector.size() - 1 - i]);
    CHECK_EQ(s.Tail(), vector[vector.size() - 1]);
    s.Pop();
  }
}

TEST_CASE_TEMPLATE("trying unique ptr", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);

  QueueArrT<T> q;
  CHECK_EQ(q.IsEmpty(), true);
  q.Push(vector[0]);
  CHECK_EQ(vector[0], q.Top());
}

TEST_CASE_TEMPLATE("trying copy ctor", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  
  QueueArrT<T> q;
  for (int i = 0; i < 8; i++) {
    q.Push(vector[i]);
    //std::cout << q.Tail() << ' ' << vector[i] << ' ' << q.Top() << std::endl;
    CHECK_EQ(q.Tail(), vector[i]);
  }
  for (int i = 0; i < 4; i++) {
    CHECK_EQ(q.Top(), vector[i]);
    //std::cout << q.Tail() << ' ' << vector[i] << ' ' << q.Top() << std::endl;
    q.Pop();
  }
  //std::cout << q.Tail() << ' ' << q.Top() << std::endl;
  q.Push(vector[8]);
  q.Push(vector[9]);
  QueueArrT<T> q_copy(q);
  CHECK_EQ(q_copy.IsEmpty(), false);
  CHECK_EQ(q_copy.Top(), vector[4]);
  CHECK_EQ(q_copy.Tail(), vector[9]);

}

TEST_CASE_TEMPLATE("operator=", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);

  QueueArrT<T> q;
  for (int i = 0; i < 8; i++) {
    q.Push(vector[i]);
    CHECK_EQ(q.Tail(), vector[i]);
  }
  for (int i = 0; i < 4; i++) {
    CHECK_EQ(q.Top(), vector[i]);
    q.Pop();
  }
  q.Push(vector[8]);
  q.Push(vector[9]);
  QueueArrT<T> q_copy(q);
  CHECK_EQ(q_copy.IsEmpty(), false);
  CHECK_EQ(q_copy.Top(), vector[4]);
  CHECK_EQ(q_copy.Tail(), vector[9]);

  QueueArrT<T> q1;
  q_copy = q1;
  CHECK_EQ(q_copy.IsEmpty(), true);
}

TEST_CASE_TEMPLATE("generic check", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  T c1(vector[0]);
  T c2(vector[1]);
  T c3(vector[2]);

  QueueArrT<T> qa;
  qa.Push(c1);
  qa.Push(c2);
  qa.Push(c3);
  CHECK_EQ(c1, qa.Top());
  qa.Pop();
  CHECK_EQ(c2, qa.Top());
  qa.Pop();
  CHECK_EQ(c3, qa.Top());
  qa.Pop();
  CHECK(qa.IsEmpty());
}

TEST_CASE_TEMPLATE("COPY_CTOR", T, int, double, std::string,  Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  T c1(vector[0]);
  T c2(vector[1]);
  T c3(vector[2]);

  QueueArrT<T> qa;
  qa.Push(c1);
  qa.Push(c2);
  qa.Push(c3);
  QueueArrT<T> qac(qa);
  CHECK_EQ(c1, qac.Top());
  qac.Pop();
  CHECK_EQ(c2, qac.Top());
  qac.Pop();
  CHECK_EQ(c3, qac.Top());
  qac.Pop();
  CHECK(qac.IsEmpty());
}

TEST_CASE_TEMPLATE("operator eq", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  T c1(vector[0]);
  T c2(vector[1]);
  T c3(vector[2]);

  QueueArrT<T> qa1;
  qa1.Push(c1);
  QueueArrT<T> qa2;
  qa2.Push(c1);
  qa2.Push(c2);
  QueueArrT<T> qa3;
  qa3.Push(c1);
  qa3.Push(c2);
  qa3.Push(c3);
  QueueArrT<T> qa2_1;
  qa2_1.Push(c1);
  qa2_1.Push(c2);
  QueueArrT<T> qa2_2;
  qa2_2.Push(c1);
  qa2_2.Push(c2);
  QueueArrT<T> qa2_3;
  qa2_3.Push(c1);
  qa2_3.Push(c2);

  qa2_1 = qa1; 
  qa2_2 = qa2;
  qa2_3 = qa3;
  
  CHECK_EQ(c1, qa2_1.Top());
  qa2_1.Pop();
  CHECK(qa2_1.IsEmpty());
  
  CHECK_EQ(c1, qa2_2.Top());
  qa2_2.Pop();
  CHECK_EQ(c2, qa2_2.Top());
  qa2_2.Pop();
  CHECK(qa2_2.IsEmpty());

  CHECK_EQ(c1, qa2_3.Top());
  qa2_3.Pop();
  CHECK_EQ(c2, qa2_3.Top());
  qa2_3.Pop();
  CHECK_EQ(c3, qa2_3.Top());
  qa2_3.Pop();
  CHECK(qa2_3.IsEmpty());
  
}

TEST_CASE_TEMPLATE("CLEAR CHECK", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  T c1(vector[0]);
  T c2(vector[1]);
  T c3(vector[2]);

  QueueArrT<T> qa;
  CHECK(qa.IsEmpty());
  qa.Push(c1);
  CHECK_FALSE(qa.IsEmpty());
  qa.Clear();
  CHECK(qa.IsEmpty());
}


TEST_CASE_TEMPLATE("TOP THROW", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  T c1(vector[0]);
  T c2(vector[1]);
  T c3(vector[2]);
  
  QueueArrT<T> qa;
  qa.Push(c1);
  CHECK_NOTHROW((void)qa.Top());
  qa.Pop();
  CHECK_THROWS((void)qa.Top());
}


TEST_CASE_TEMPLATE("MOVE SEMANTICS") {
  std::vector <T> test;
  make_vector(10, test);
  T c1(vector[0]);
  T c2(vector[1]);
  T c3(vector[2]);

  QueueArrT<T> qa_parent;
  qa_parent.Push(c3);
  qa_parent.Push(c3);
  qa_parent.Push(c3);
  qa_parent.Push(c2);
  qa_parent.Push(c1);
  QueueArrT<T> qa_0(qa_parent);
  

  auto start_1{ std::chrono::steady_clock::now() };
  QueueArrT<T> qa_1(qa_parent);
  auto end_1{ std::chrono::steady_clock::now() };
  
  auto start_2{ std::chrono::steady_clock::now() };
  QueueArrT<T> qa_2(std::move(qa_parent));
  auto end_2{ std::chrono::steady_clock::now() };
  
  qa_parent = qa_0;
  auto start_3{ std::chrono::steady_clock::now() };
  QueueArrT<T> qa_3 = std::move(qa_parent);
  auto end_3{ std::chrono::steady_clock::now() };
  
  std::chrono::nanoseconds elapsed_1(end_1 - start_1);
  std::chrono::nanoseconds elapsed_2(end_2 - start_2);
  std::chrono::nanoseconds elapsed_3(end_3 - start_3);

  // std::cout << elapsed_1 << ' ' << elapsed_2 << ' ' << elapsed_3;

  CHECK_EQ(c3, qa_1.Top());
  qa_1.Pop();
  CHECK_EQ(c3, qa_1.Top());
  qa_1.Pop();
  CHECK_EQ(c3, qa_1.Top());
  qa_1.Pop();
  CHECK_EQ(c2, qa_1.Top());
  qa_1.Pop();
  CHECK_EQ(c1, qa_1.Top());
  qa_1.Pop();
  CHECK(qa_1.IsEmpty());

  CHECK_EQ(c3, qa_2.Top());
  qa_2.Pop();
  CHECK_EQ(c3, qa_2.Top());
  qa_2.Pop();
  CHECK_EQ(c3, qa_2.Top());
  qa_2.Pop();
  CHECK_EQ(c2, qa_2.Top());
  qa_2.Pop();
  CHECK_EQ(c1, qa_2.Top());
  qa_2.Pop();
  CHECK(qa_2.IsEmpty());

  CHECK_EQ(c3, qa_3.Top());
  qa_3.Pop();
  CHECK_EQ(c3, qa_3.Top());
  qa_3.Pop();
  CHECK_EQ(c3, qa_3.Top());
  qa_3.Pop();
  CHECK_EQ(c2, qa_3.Top());
  qa_3.Pop();
  CHECK_EQ(c1, qa_3.Top());
  qa_3.Pop();
  CHECK(qa_3.IsEmpty());


  CHECK(elapsed_2 + std::chrono::nanoseconds(200) < elapsed_1);
  CHECK(elapsed_3 + std::chrono::nanoseconds(200) < elapsed_1);
  
}


TEST_CASE_TEMPLATE("copy ctor + operator= are acting up", T, int, double, std::string, Complex, Rational) {
  std::vector <T> vector;
  make_vector(10, vector);
  T c1(vector[0]);
  T c2(vector[1]);
  T c3(vector[2]);
  
  QueueArrT<T> q;
  QueueArrT<T> a(q);
  CHECK_EQ(a.IsEmpty(), true);
  QueueArrT<T> b = q;
  CHECK_EQ(b.IsEmpty(), true);
  b.Push(c1);
  b.Push(c2);
  b.Push(c3);
  b = q;
  CHECK_EQ(b.IsEmpty(), true);
  QueueArrT<T> b1(b);
  CHECK(b1.IsEmpty() == 1);
  //CHECK(b1.Top() == T(1, 0));
  CHECK_THROWS(b1.Top());
} 


