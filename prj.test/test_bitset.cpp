#include <bitset/bitset.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("were starting") {
  BitSet b;
  CHECK(b.Size() == 0);
  BitSet b1(5);
  CHECK(b1.Size() == 5);
}