#include <queuelstprt/queuelstprt.hpp>
#include "vector.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
//#include <complex/complex.hpp>

TEST_CASE_TEMPLATE("were going down", T, int, double,  std::string, Rational) {
  std::vector <T> vector = make_vector<T>();

  QueueLstPrT<T> q;
  CHECK_EQ(q.IsEmpty(), 1);
  CHECK_THROWS(q.Top());
  for (int i = 0; i < vector.size(); i++) {
    q.Push(vector[i]);
    //std::cout << vector[i];
    CHECK_EQ(q.IsEmpty(), 0);
  }
  for (int i = 0; i < 6; i++) {
    q.Pop();
  }
}

TEST_CASE_TEMPLATE("generic test 0", T, int, double, std::string, Rational) {
  std::vector <T> vector = make_vector<T>();
  T c1 = vector[3]; 
  T c2 = vector[1]; 
  T c3 = vector[2]; 

  QueueLstPrT<T> qlp;
  CHECK(qlp.IsEmpty());
  qlp.Push(c1);
  CHECK_FALSE(qlp.IsEmpty());
  qlp.Push(c2);
  qlp.Push(c3);
  CHECK_FALSE(qlp.IsEmpty());
  CHECK_EQ(qlp.Top(), c2);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c3);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE_TEMPLATE("copy_ctor", T, int, double, std::string, Rational) {
  std::vector <T> vector = make_vector<T>();
  T c1 = vector[3]; 
  T c2 = vector[1]; 
  T c3 = vector[2]; 

  QueueLstPrT<T> qlp;
  qlp.Push(c1);
  qlp.Push(c2);
  qlp.Push(c3);
  QueueLstPrT<T> qlp_c(qlp);

  CHECK_EQ(qlp.Top(), c2);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c3);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK(qlp.IsEmpty());

  CHECK_EQ(qlp_c.Top(), c2);
  qlp_c.Pop();
  CHECK_EQ(qlp_c.Top(), c3);
  qlp_c.Pop();
  CHECK_EQ(qlp_c.Top(), c1);
  qlp_c.Pop();
  CHECK(qlp_c.IsEmpty());
}

TEST_CASE_TEMPLATE("copy_ctor 2", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3];
  T c2 = vector[1];
  T c3 = vector[2];

  QueueLstPrT<T> qlp;
  qlp.Push(c3);
  qlp.Push(c2);
  qlp.Push(c1);
  qlp.Push(c3);
  qlp.Push(c2);
  QueueLstPrT<T> qlp_c(qlp);

  CHECK_EQ(c2, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c2, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c3, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c3, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c1, qlp.Top());
  qlp.Pop();
  CHECK(qlp.IsEmpty());

  CHECK_EQ(c2, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(c2, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(c3, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(c3, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(c1, qlp_c.Top());
  qlp_c.Pop();
  CHECK(qlp_c.IsEmpty());
}

TEST_CASE_TEMPLATE("eq_ctor", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3];
  T c2 = vector[1];
  T c3 = vector[2];
  
  QueueLstPrT<T> qlp;
  qlp.Push(c1);
  qlp.Push(c2);
  qlp.Push(c3);
  QueueLstPrT<T> qlp_e = qlp;

  CHECK_EQ(qlp.Top(), c2);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c3);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK(qlp.IsEmpty());

  CHECK_EQ(qlp_e.Top(), c2);
  qlp_e.Pop();
  CHECK_EQ(qlp_e.Top(), c3);
  qlp_e.Pop();
  CHECK_EQ(qlp_e.Top(), c1);
  qlp_e.Pop();
  CHECK(qlp_e.IsEmpty());
}

TEST_CASE_TEMPLATE("eq ctor 2", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3]; //35r
  T c2 = vector[1]; //-1300
  T c3 = vector[2]; //c3

  QueueLstPrT<T> qlp;
  qlp.Push(c3);
  qlp.Push(c2);
  qlp.Push(c1);
  qlp.Push(c3);
  qlp.Push(c2);
  QueueLstPrT<T> qlp_c = qlp;

  CHECK_EQ(c2, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c2, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c3, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c3, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c1, qlp.Top());
  qlp.Pop();
  CHECK(qlp.IsEmpty());

  CHECK_EQ(c2, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(c2, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(c3, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(c3, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(c1, qlp_c.Top());
  qlp_c.Pop();
  CHECK(qlp_c.IsEmpty());
}

TEST_CASE_TEMPLATE("generic test 1", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3]; 
  T c2 = vector[1]; 
  T c3 = vector[2]; 

  QueueLstPrT<T> qlp;
  qlp.Push(c1);
  qlp.Push(c2);
  qlp.Push(c3);

  CHECK_EQ(qlp.Top(), c2);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c3);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE_TEMPLATE("generic test 1 (five elems)", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3];
  T c2 = vector[1];
  T c3 = vector[2];
  
  QueueLstPrT<T> qlp;
  qlp.Push(c3);
  qlp.Push(c2);
  qlp.Push(c1);
  qlp.Push(c3);
  qlp.Push(c2);

  CHECK_EQ(c2, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c2, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c3, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c3, qlp.Top());
  qlp.Pop();
  CHECK_EQ(c1, qlp.Top());
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE_TEMPLATE("generic test 2 (chain to right side)", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3];
  T c2 = vector[1];
  T c3 = vector[2];

  
  QueueLstPrT<T> qlp;
  qlp.Push(c2);
  qlp.Push(c3);
  qlp.Push(c1);

  CHECK_EQ(qlp.Top(), c2);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c3);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE_TEMPLATE("generic test 3 (chain to left side)", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3];
  T c2 = vector[1];
  T c3 = vector[2]; 
  
  QueueLstPrT<T> qlp;
  qlp.Push(c1);
  qlp.Push(c3);
  qlp.Push(c2);

  CHECK_EQ(qlp.Top(), c2);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c3);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE_TEMPLATE("generic test 4 (same elems)", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3];
  T c2 = vector[1];
  T c3 = vector[2]; 
  
  QueueLstPrT<T> qlp;
  qlp.Push(c1);
  qlp.Push(c1);
  qlp.Push(c1);
  qlp.Push(c3);
  qlp.Push(c3);

  CHECK_EQ(qlp.Top(), c3);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c3);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), c1);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE_TEMPLATE("MOVE SEMANTICS", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  T c1 = vector[3];
  T c2 = vector[1]; 
  T c3 = vector[2];
  
  QueueLstPrT<T> qlp_parent;
  qlp_parent.Push(c3);
  qlp_parent.Push(c2);
  qlp_parent.Push(c1);
  qlp_parent.Push(c3);
  qlp_parent.Push(c2);
  QueueLstPrT<T> qlp_0(qlp_parent);

  auto start_1{ std::chrono::steady_clock::now() };
  QueueLstPrT<T> qlp_1(qlp_parent);
  auto end_1{ std::chrono::steady_clock::now() };

  auto start_2{ std::chrono::steady_clock::now() };
  QueueLstPrT<T> qlp_2(std::move(qlp_parent));
  auto end_2{ std::chrono::steady_clock::now() };

  qlp_parent = qlp_0;
  auto start_3{ std::chrono::steady_clock::now() };
  QueueLstPrT<T> qlp_3 = std::move(qlp_parent);
  auto end_3{ std::chrono::steady_clock::now() };

  std::chrono::nanoseconds elapsed_1(end_1 - start_1);
  std::chrono::nanoseconds elapsed_2(end_2 - start_2);
  std::chrono::nanoseconds elapsed_3(end_3 - start_3);

  // std::cout << elapsed_1 << ' ' << elapsed_2 << ' ' << elapsed_3;

  CHECK_EQ(c2, qlp_1.Top());
  qlp_1.Pop();
  CHECK_EQ(c2, qlp_1.Top());
  qlp_1.Pop();
  CHECK_EQ(c3, qlp_1.Top());
  qlp_1.Pop();
  CHECK_EQ(c3, qlp_1.Top());
  qlp_1.Pop();
  CHECK_EQ(c1, qlp_1.Top());
  qlp_1.Pop();
  CHECK(qlp_1.IsEmpty());

  CHECK_EQ(c2, qlp_2.Top());
  qlp_2.Pop();
  CHECK_EQ(c2, qlp_2.Top());
  qlp_2.Pop();
  CHECK_EQ(c3, qlp_2.Top());
  qlp_2.Pop();
  CHECK_EQ(c3, qlp_2.Top());
  qlp_2.Pop();
  CHECK_EQ(c1, qlp_2.Top());
  qlp_2.Pop();
  CHECK(qlp_2.IsEmpty());

  CHECK_EQ(c2, qlp_3.Top());
  qlp_3.Pop();
  CHECK_EQ(c2, qlp_3.Top());
  qlp_3.Pop();
  CHECK_EQ(c3, qlp_3.Top());
  qlp_3.Pop();
  CHECK_EQ(c3, qlp_3.Top());
  qlp_3.Pop();
  CHECK_EQ(c1, qlp_3.Top());
  qlp_3.Pop();
  CHECK(qlp_3.IsEmpty());


  CHECK(elapsed_2 + std::chrono::nanoseconds(200) < elapsed_1);
  CHECK(elapsed_3 + std::chrono::nanoseconds(200) < elapsed_1);
}

TEST_CASE_TEMPLATE("QueueLstPrT<T> constructors", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();

  QueueLstPrT<T> queue;
  CHECK(queue.IsEmpty());

  QueueLstPrT<T> queue1;
  queue1.Push(vector[1]);
  QueueLstPrT<T> queue2(queue1);
  QueueLstPrT<T> queue3;
  queue3 = queue2;
  CHECK_FALSE(queue3.IsEmpty());

  QueueLstPrT<T> queue4(std::move(queue3));
  CHECK(queue4.Top() == vector[1]);
  CHECK(queue3.IsEmpty());
}

TEST_CASE_TEMPLATE("QueueLstPrT<T> - IsEmpty", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();
  QueueLstPrT<T> queue;
  CHECK(queue.IsEmpty());
  queue.Push(vector[1]);
  CHECK(!queue.IsEmpty());
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE_TEMPLATE("QueueLstPrT<T> - right order", T, int, double, std::string, Rational) {
  std::vector<T> vector = make_vector<T>();

  QueueLstPrT<T> queue;
  queue.Push(vector[1]);
  queue.Push(vector[3]);
  queue.Push(vector[2]);
  queue.Print();
  CHECK(queue.Top() == vector[1]);
  queue.Pop();
  CHECK(queue.Top() == vector[2]);
  queue.Pop();
  CHECK(queue.Top() == vector[3]);
  queue.Pop();
  CHECK(queue.IsEmpty());
}