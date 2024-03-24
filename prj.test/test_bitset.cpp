#include <bitset/bitset.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("up we go") {
  BitSet b;
  CHECK(b.Size() == 0);
  BitSet b1(5);
  CHECK(b1.Size() == 5);
  b1.Fill(1);
  b1.Print();
  b1.Set(2, 0);
  b1.Set(0, 0);
  b1.Print();
  BitSet b2(5);
  b2.Fill(0);
  b2.Set(4, 1);
  b2.Print();
  b2 ^= b1;
  b2.Print();

}