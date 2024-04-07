#include <bitset/bitset.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("up we go") {
  BitSet b;
  CHECK(b.Size() == 0);
  BitSet b1(5);
  CHECK(b1.Size() == 5);
  b1.Fill(1);
  //b1.Print();
  b1.Set(2, 0);
  b1.Set(0, 0);
  //b1.Print();
  BitSet b2(5);
  //b2.Fill(0);
  b2.Set(4, 1);
  //b2.Print();
  b2 ^= b1;
  //b2.Print();

}

/*
TEST_CASE("Set, Get, Resize") {
  BitSet bs;
  CHECK(bs.Size() == 0);
  bs.Resize(49);
  CHECK_FALSE(bs.Size() == 0);
  for (int i = 0; i < 49; ++i) {
    CHECK_FALSE(bs.Get(i));
  }

  for (int i = 0; i < 49; ++i) {
    bs.Set(i, true);
  }

  for (int i = 0; i < 49; ++i) {
    CHECK(bs.Get(i));
  }

  bs.Resize(60);
  for (int i = 0; i < 49; ++i) {
    CHECK(bs.Get(i));
  }
  for (int i = 49; i < 60; ++i) {
    CHECK_FALSE(bs.Get(i));
  }

  bs.Resize(38);
  for (int i = 0; i < 38; ++i) {
    CHECK(bs.Get(i));
  }

  bs.Resize(60);
  for (int i = 0; i < 38; ++i) {
    CHECK(bs.Get(i));
  }
  for (int i = 38; i < 60; ++i) {
    CHECK_FALSE(bs.Get(i));
  }
}
*/
/*
TEST_CASE("Set, Get, Resize - pt.2") {
  BitSet bs;
  CHECK_THROWS((void)bs.Get(0));
  CHECK_THROWS(bs.Set(0, false));
  bs.Resize(3);
  CHECK_THROWS((void)bs.Get(3));
  CHECK_THROWS(bs.Set(3, false));
  CHECK_THROWS(bs.Resize(-1));
}
*/
/*
TEST_CASE("copy ctor") {
  BitSet bs;
  bs.Resize(49);
  for (int i = 0; i < 49; ++i) {
    bs.Set(i, true);
  }

  BitSet bs1(bs);
  BitSet bs2 = bs;

  for (int i = 0; i < 49; ++i) {
    CHECK_EQ(bs.Get(i), bs1.Get(i));
    CHECK_EQ(bs.Get(i), bs2.Get(i));
  }

  CHECK_THROWS((void)bs.Get(49));
  CHECK_THROWS((void)bs1.Get(49));
  CHECK_THROWS((void)bs2.Get(49));
}

*/
TEST_CASE("operator[]") {
  BitSet bs(4);
  //bs.Fill(false);
  //bs.Set(1, true);
  //bs.Set(3, true);
  //CHECK_FALSE(bs[0]);
  //CHECK(bs[1]);
  //CHECK_FALSE(bs[2]);
  //CHECK(bs[3]);

  //bs[0] = true;
  //bs[1] = true;
  //bs[2] = false;
  //bs[3] = false;

  //CHECK(bs[0]);
  //CHECK(bs[1]);
  //CHECK_FALSE(bs[2]);
  //CHECK_FALSE(bs[3]);
}
