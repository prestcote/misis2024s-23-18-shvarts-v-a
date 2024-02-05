#include <dynarr/dynarr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/*
TEST_CASE("dynarr ctor") {
  DynArr arr_def;

  CHECK_EQ(arr_def.Size(), 0);

  const int size = 5;
  DynArr arr_s(size);
  CHECK_EQ(arr_s.Size(), size);

  CHECK_THROWS(void(DynArr(0)));
  CHECK_THROWS(void(DynArr(-size)));
}

TEST_CASE("dynarr op[]") {
  const int size = 5;
  DynArr arr(size);
  CHECK(arr[0] == 0);
  CHECK_EQ(arr[arr.Size() - 1], 0);
  CHECK_THROWS(arr[-1]);
  CHECK_THROWS(arr[arr.Size()]);
}

TEST_CASE("something about copy") {
  DynArr arr(5);
  DynArr copy(arr);
  CHECK_EQ(copy.Size(), 5);
  DynArr arr_2(7);
  //copy = arr_2;
  arr.Resize(7);
  CHECK_EQ(arr.Size(), 7);
  arr.Resize(5);
  CHECK_EQ(arr.Size(), 5);
}

TEST_CASE("im dead") {
  DynArr arr(5);
  DynArr arr_2(3);
  arr = arr_2;
  CHECK_EQ(arr.Size(), 3);
}  */
/*
TEST_CASE("dynarr ctor") {
  DynArr arr_def;
  CHECK_EQ(arr_def.Size(), 0);
  CHECK_THROWS(arr_def[0]);

  const int size = 5;
  DynArr arr_s(size);
  CHECK_EQ(arr_s.Size(), size);

  CHECK_THROWS(void(DynArr(0)));
  CHECK_THROWS(void(DynArr(-size)));
}

TEST_CASE("dynarr op[]") {
  int size = 5;
  DynArr arr(size);
  CHECK_EQ(arr[0], 0);
  CHECK_EQ(arr[arr.Size() - 1], 0);
  CHECK_THROWS(arr[-1]);
  CHECK_THROWS(arr[arr.Size()]);

  int elem = arr[0];
  CHECK_EQ(elem, 0);
  arr[0] = 1;
  CHECK_EQ(elem, 0);
  elem = 3;
  CHECK_EQ(arr[0], 1);

  arr[0] = 0;
  const int k_elem = arr[0];
  CHECK_EQ(k_elem, 0);
}

TEST_CASE("dynarr_enlarge") {
  DynArr arr(5);
  for (int i = 0; i < 5; ++i) {
    arr[i] = i + 1;
  }
  arr.Resize(10);
  CHECK_EQ(arr.Size(), 10);
  for (int i = 0; i < 5; ++i) {
    CHECK_EQ(arr[i], i + 1);
  }
  for (int i = 5; i < 10; ++i) {
    CHECK_EQ(arr[i], 0);
  }
}

TEST_CASE("dynarr_shorten") {
  DynArr arr(5);
  for (int i = 0; i < 5; ++i) {
    arr[i] = i + 1;
  }
  arr.Resize(3);
  CHECK_EQ(arr.Size(), 3);
  CHECK_EQ(arr.Capacity(), 5);
  for (int i = 0; i < 3; ++i) {
    CHECK_EQ(arr[i], i + 1);
  }

  CHECK_THROWS(arr.Resize(0));
  CHECK_THROWS(arr.Resize(-1));

  arr.Resize(5);
  CHECK_EQ(arr.Size(), 5);
  CHECK_EQ(arr.Capacity(), 5);
  for (int i = 0; i < 3; ++i) {
    CHECK_EQ(arr[i], i + 1);
  }
  for (int i = 3; i < 5; ++i) {
    CHECK_EQ(arr[i], 0);
  }
}

TEST_CASE("arr copy") {
  DynArr arr(5);
  for (int i = 0; i < 5; ++i) {
    arr[i] = i + 1;
  }
  DynArr arr1 = arr;
  DynArr arr2(arr);
  CHECK_EQ(arr1.Size(), 5);
  CHECK_EQ(arr2.Size(), 5);
  for (int i = 0; i < 5; ++i) {
    CHECK_EQ(arr1[i], i + 1);
    CHECK_EQ(arr2[i], i + 1);
  }

  for (int i = 0; i < 5; ++i) {
    arr[i] = i + 2;
  }
  for (int i = 0; i < 5; ++i) {
    CHECK_EQ(arr1[i], i + 1);
    CHECK_EQ(arr2[i], i + 1);
  }
}
*/

TEST_CASE("dynarr ctor") {
  DynArr arr_def;
  CHECK_EQ(arr_def.Size(), 0); 
  const int size = 5;
  DynArr arr_s(size);
  CHECK_EQ(arr_s[0], 0);
  CHECK_EQ(arr_s.Size(), size);
  CHECK_THROWS(void(DynArr(0)));
  CHECK_THROWS(void(DynArr(-size)));
}

TEST_CASE("dynarr op") {
  const int size = 5;
  DynArr arr1(size);
  CHECK_EQ(arr1[0], 0);
  CHECK_EQ(arr1[arr1.Size() - 1], 0);
  CHECK_THROWS(arr1[-1]);
  CHECK_THROWS(arr1[arr1.Size()]);
}

TEST_CASE("check") {
  DynArr da(4);
  CHECK_EQ(da.Size(), 4);
  da.Resize(3);
  CHECK_EQ(da.Size(), 3);
  da[2] = 2.2f;
  float x = da[2];
  DynArr da2 = da;
  CHECK_EQ(x, 2.2f);
  CHECK_EQ(da2[2], da[2]);
  CHECK_FALSE(&da2[2] == &da[2]);
  CHECK_THROWS(da.Resize(-1));
  CHECK_THROWS(da.Resize(0));
  CHECK_THROWS(DynArr(-1));
};

/*
TEST_CASE("check cout") {
  DynArr da(5);
  for (int x = 0; x < 4; x += 1) {
    da[x] = x;
  }
  std::ostringstream ostr("");
  ostr.str("");
  ostr << da;
  CHECK_EQ(ostr.str(), "0 1 2 3 0");
};
*/




