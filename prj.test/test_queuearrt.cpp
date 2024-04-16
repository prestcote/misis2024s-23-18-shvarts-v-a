#include <queuearrt/queuearrt.hpp>
#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("one more time") {
  QueueArrT<Complex> q;
  CHECK(q.IsEmpty() == true);
  CHECK(q.Size() == 0);
}

TEST_CASE("wellllll") {
  QueueArrT<Complex> s;
  s.Push(Complex(1, 1));
  CHECK(s.IsEmpty() == false);
  CHECK(s.Top() == Complex(1, 1));
  //CHECK(s.Tail() == Complex(1, 1));
  s.Push(Complex(1, 2));
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 3));
  //std::cout << s.Top() << s.Tail() << std:: endl;
  s.Push(Complex(1, 4));
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 5));
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 6));
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Pop();
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Pop();
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Pop();
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 10));
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 11));
  //std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 12));
  s.Push(Complex(1, 13));

}

TEST_CASE("trying unique ptr") {
  QueueArrT<Complex> q;
  CHECK_EQ(q.IsEmpty(), true);
  q.Push(Complex(1, 1));
  std::cout << q.Top() << std::endl;
  std::cout << std::endl;
}

TEST_CASE("trying copy ctor") {
  QueueArrT<Complex> q;
  q.Push(Complex(1, 1));
  q.Push(Complex(1, 2));
  q.Push(Complex(1, 3));
  q.Push(Complex(1, 4));
  q.Push(Complex(1, 5));
  q.Push(Complex(1, 6));
  q.Push(Complex(1, 7));
  q.Push(Complex(1, 8));
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Push(Complex(1, 9));
  q.Push(Complex(1, 10));
  QueueArrT<Complex> q_copy(q);
 // std::cout << q.Top() << q.Tail() << std::endl;
 // std::cout << q_copy.Top() << q_copy.Tail() << std::endl;

}

TEST_CASE("operator=") {
  QueueArrT<Complex> q;
  q.Push(Complex(1, 1));
  q.Push(Complex(1, 2));
  q.Push(Complex(1, 3));
  q.Push(Complex(1, 4));
  q.Push(Complex(1, 5));
  q.Push(Complex(1, 6));
  q.Push(Complex(1, 7));
  q.Push(Complex(1, 8));
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Push(Complex(1, 9));
  q.Push(Complex(1, 10));
  QueueArrT<Complex> q_copy;
  q_copy = q;
 // std::cout << q.Top() << q.Tail() << std::endl;
  //std::cout << q_copy.Top() << q_copy.Tail() << std::endl;
  QueueArrT<Complex> q1;
  q_copy = q1;
  CHECK_EQ(q_copy.IsEmpty(), true);
}

Complex c1(1, 2);
Complex c2(2, 3);
Complex c3(3, 4);

TEST_CASE("generic check") {
  QueueArrT<Complex> qa;
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

TEST_CASE("COPY_CTOR") {
  QueueArrT<Complex> qa;
  qa.Push(c1);
  qa.Push(c2);
  qa.Push(c3);
  QueueArrT<Complex> qac(qa);
  CHECK_EQ(c1, qac.Top());
  qac.Pop();
  CHECK_EQ(c2, qac.Top());
  qac.Pop();
  CHECK_EQ(c3, qac.Top());
  qac.Pop();
  CHECK(qac.IsEmpty());
}

TEST_CASE("operator eq") {
  QueueArrT<Complex> qa1;
  qa1.Push(c1);
  QueueArrT<Complex> qa2;
  qa2.Push(c1);
  qa2.Push(c2);
  QueueArrT<Complex> qa3;
  qa3.Push(c1);
  qa3.Push(c2);
  qa3.Push(c3);
  QueueArrT<Complex> qa2_1;
  qa2_1.Push(c1);
  qa2_1.Push(c2);
  QueueArrT<Complex> qa2_2;
  qa2_2.Push(c1);
  qa2_2.Push(c2);
  QueueArrT<Complex> qa2_3;
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

TEST_CASE("CLEAR CHECK") {
  QueueArrT<Complex> qa;
  CHECK(qa.IsEmpty());
  qa.Push(c1);
  CHECK_FALSE(qa.IsEmpty());
  qa.Clear();
  CHECK(qa.IsEmpty());
}


TEST_CASE("TOP THROW") {
  QueueArrT<Complex> qa;
  qa.Push(c1);
  CHECK_NOTHROW((void)qa.Top());
  qa.Pop();
  CHECK_THROWS((void)qa.Top());
}


TEST_CASE("MOVE SEMANTICS") {
  QueueArrT<Complex> qa_parent;
  qa_parent.Push(c3);
  qa_parent.Push(c3);
  qa_parent.Push(c3);
  qa_parent.Push(c2);
  qa_parent.Push(c1);
  QueueArrT<Complex> qa_0(qa_parent);
  

  auto start_1{ std::chrono::steady_clock::now() };
  QueueArrT<Complex> qa_1(qa_parent);
  auto end_1{ std::chrono::steady_clock::now() };
  
  auto start_2{ std::chrono::steady_clock::now() };
  QueueArrT<Complex> qa_2(std::move(qa_parent));
  auto end_2{ std::chrono::steady_clock::now() };
  
  qa_parent = qa_0;
  auto start_3{ std::chrono::steady_clock::now() };
  QueueArrT<Complex> qa_3 = std::move(qa_parent);
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


TEST_CASE("copy ctor + operator= are acting up") {
  QueueArrT<Complex> q;
  QueueArrT<Complex> a(q);
  CHECK_EQ(a.IsEmpty(), true);
  QueueArrT<Complex> b = q;
  CHECK_EQ(b.IsEmpty(), true);
  b.Push(Complex(1, 0));
  b.Push(Complex(2, 0));
  b.Push(Complex(3, 0));
  b = q;
  CHECK_EQ(b.IsEmpty(), true);
  QueueArrT<Complex> b1(b);
  CHECK(b1.IsEmpty() == 1);
  //CHECK(b1.Top() == Complex(1, 0));
  CHECK_THROWS(b1.Top());
} 

