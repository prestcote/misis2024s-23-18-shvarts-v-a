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
  s.Pop();
  std::cout << s.Top() << s.Tail() << std::endl;
}