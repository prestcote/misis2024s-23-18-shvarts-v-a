#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("just something") {
  CHECK(Complex(0, 1) == -(-(Complex(0, 1))));
  CHECK(Complex(-1, 2) == -Complex(1, -2));
  CHECK(Complex(1, 2) == (Complex(0, 2) + 1));
  CHECK(Complex(1, 2) == (Complex(0, 2) + Complex(1)));
  CHECK(Complex(0, 1) == (Complex() + Complex(0, 1)));
  CHECK(Complex(-1, 2) == (Complex(0, 2) - 1));
  CHECK(Complex(1, -2) == (1 - Complex(0, 2)));
  CHECK(Complex(0, 1) == (Complex(1, 1) - Complex(1)));
  CHECK(Complex(0, -1) == (Complex() - Complex(0, 1)));
  CHECK(Complex(2, 4) == Complex(1, 2) * 2);
  CHECK(Complex(2, 4) == 2.0 * Complex(1, 2));
  CHECK(Complex(-4, 7) == Complex(1, 2) * Complex(2, 3));
  CHECK((Complex(8) /= Complex(2, 3)) == (Complex(8) * Complex(2, -3)) / (Complex(2, 3) * Complex(2, -3)));
  CHECK(Complex(2, 4) / 2 == Complex(1, 2));
  CHECK(8 / Complex(2, 3) == Complex(16.0 / 13, -24.0 / 13));
  CHECK(Complex(8) / Complex(2, 3) == (Complex(8) * Complex(2, -3)) / (Complex(2, 3) * Complex(2, -3)));

}
