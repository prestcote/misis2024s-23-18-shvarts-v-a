#include <queuearr/queuearr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("wellllll") {
  QueueArr s;
  s.Push(Complex(1, 1));
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 2));
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 3));
  std::cout << s.Top() << s.Tail() << std:: endl;
  s.Push(Complex(1, 4));
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 5));
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 6));
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Pop();
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Pop();
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Pop();
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 10));
  std::cout << s.Top() << s.Tail() << std::endl;
  s.Push(Complex(1, 11));
  std::cout << s.Top() << s.Tail() << std::endl;

}

TEST_CASE("trying unique ptr") {
  QueueArr q;
  CHECK_EQ(q.IsEmpty(), true);
  q.Push(Complex(1, 1));
  std::cout << q.Top() << std::endl;
  std::cout << std::endl;
}

TEST_CASE("trying copy ctor") {
  QueueArr q;
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
  QueueArr q_copy(q);
  std::cout << q.Top() << q.Tail() << std::endl;
  std::cout << q_copy.Top() << q_copy.Tail() << std::endl;

}

TEST_CASE("operator=") {
  QueueArr q;
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
  QueueArr q_copy;
  q_copy = q;
  std::cout << q.Top() << q.Tail() << std::endl;
  std::cout << q_copy.Top() << q_copy.Tail() << std::endl;
  QueueArr q1;
  q_copy = q1;
  CHECK_EQ(q_copy.IsEmpty(), true);
}