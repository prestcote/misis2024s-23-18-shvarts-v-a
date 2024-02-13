#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

TEST_CASE("were sooo down") {
  StackLst s;
  s.Push(Complex(1, 2));
}