
#include <rational/rational.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Rational ctor") {
  CHECK_THROWS(Rational(1, 0));
  CHECK_THROWS(void(Rational(1, 0)));

  Rational zero_rational;
  CHECK(zero_rational.num() == 0);
  CHECK(zero_rational.den() == 1);

  Rational int_rational(4);
  CHECK(int_rational.num() == 4);
  CHECK(int_rational.den() == 1);

  Rational neg_num_rational(-4, 5);
  CHECK(neg_num_rational.num() == -4);
  CHECK(neg_num_rational.den() == 5);

  Rational neg_den_rational(4, -5);
  CHECK(neg_den_rational.num() == -4);
  CHECK(neg_den_rational.den() == 5);

  Rational neg_both_rational(-4, -5);
  CHECK(neg_both_rational.num() == 4);
  CHECK(neg_both_rational.den() == 5);

  CHECK_THROWS(Rational(1, 0));

  Rational div_rational(20, 25);
  CHECK(div_rational.num() == 4);
  CHECK(div_rational.den() == 5);

  Rational copy(1, 2);
  Rational copycat(copy);
  CHECK(copycat.num() == 1);
  CHECK(copycat.den() == 2);
}

TEST_CASE("rational eqations") {
  CHECK(Rational(2, 4) == Rational(-1, -2));
  CHECK(Rational(0, 1) == Rational(0, 100));
  CHECK(Rational(1, 2) != Rational(0, 2));
  CHECK(Rational(2, 4) >= Rational(-1, -2));
  CHECK(Rational(0, 1) >= Rational(0, 100));
  CHECK(Rational(2, 4) <= Rational(-1, -2));
  CHECK(Rational(0, 1) <= Rational(0, 100));
  CHECK(Rational(1, 3) < Rational(2, 3));
  CHECK((Rational(1, 3) > Rational(2, 3)) == false);
  CHECK(Rational(2, 3) > Rational(1, 3));
  CHECK((Rational(2, 3) < Rational(1, 3)) == false);
}

TEST_CASE("rational add") {
  Rational r1(1, 5);
  Rational r2(4, 5);
  Rational ans1 = r1 + r2;
  Rational ans2 = r1;
  ans2 += r2;
  Rational ans3 = r2;
  ans3 += r1;
  CHECK(ans1 == ans2);
  CHECK(ans2 == ans3);
  CHECK(ans3 == Rational(1));
}

TEST_CASE("rational sub") {
  Rational r1(1, 5);
  Rational r2(4, 5);
  Rational ans1 = r1 - r2;
  Rational ans2 = r1;
  ans2 -= r2;
  CHECK(ans1 == ans2);
  CHECK(ans2 == Rational(-3, 5));
}

TEST_CASE("rational mul") {
  Rational r1(2, 3);
  Rational r2(8, 2);
  int64_t r3 = 4;
  Rational ans1 = r1 * r2;
  Rational ans2 = r1;
  ans2 *= r2;
  CHECK(ans1 == ans2);
  CHECK(ans2 == Rational(8, 3));
  
  Rational ans3 = r1 * r3;
  Rational ans4 = r3 * r1;
  Rational ans5 = r1;
  ans5 *= r3;
  CHECK(ans3 == ans4);
  CHECK(ans4 == ans5);
  CHECK(ans5 == Rational(8, 3));
}

TEST_CASE("rational div") {
  Rational r1(2, 3);
  Rational r2(2, 8);
  int64_t r3 = 4;
  Rational ans1 = r1 / r2;
  Rational ans2 = r1;
  ans2 /= r2;
  CHECK(ans1 == ans2);
  CHECK(ans2 == Rational(8, 3));

  Rational ans3 = r1 / r3;
  Rational ans4 = r1;
  ans4 /= r3;
  CHECK(ans3 == ans4);
  CHECK(ans4 == Rational(1, 6));

  CHECK_THROWS(Rational(1, 2) / Rational(0, 5));
  CHECK_THROWS(Rational(1, 2) / 0);
}

TEST_CASE("rational input") {
  std::istringstream input("5/8");
  Rational r1;
  input >> r1;
  CHECK(r1 == Rational(5 / 8));
}

TEST_CASE("rational output") {
  std::ostringstream output;
  Rational r1(2, 3);
  output << r1;
  CHECK(output.str() == "2/3");
}

TEST_CASE("arithmetics (borrowed from Egor Chistov)") {
  Rational r23(2, 3);
  Rational r12(1, 2);
  Rational r76(7, 6);
  Rational r16(1, 6);

  Rational rr1 = r23 + r12;
  Rational rr2 = r76 - 1;
  Rational rr3 = 7 * r16;

  CHECK_EQ(rr1, r76);
  CHECK_EQ(r16, rr2);
  CHECK_EQ(rr3, r16 * 7);
  CHECK_EQ(r76, 7 * r16);
  CHECK_EQ(r16, r76 / 7);

  CHECK_EQ(Rational(3, 4), -Rational(3, -4));
  CHECK_EQ(Rational(0), -Rational(0));
  CHECK_EQ(Rational(3, 4), -Rational(-3, 4));
}; 
/*
TEST_CASE("IO") {
  std::istringstream istream("2/3");
  Rational reading;
  Rational r23(2, 3);

  istream >> reading;
  CHECK_FALSE(istream.fail());
  CHECK(reading.num() == 2);
  CHECK(reading.den() == 3);

  std::istringstream istream2("4/5");
  istream2 >> reading;
  CHECK(reading.num() == 4);
  CHECK(reading.den() == 5);

  std::istringstream istream3("7/8");
  istream3 >> reading;
  CHECK(reading.num() == 7);
  CHECK(reading.den() == 8);

  std::istringstream istream4("-712/38");
  istream4 >> reading;
  CHECK(reading.num() == -712);
  CHECK(reading.den() == 38);

  std::istringstream istream5("-123 / 48");
  istream5 >> reading;
  CHECK(reading.num() == -123);
  CHECK(reading.den() == 48);

  std::istringstream istream6("7/ -8");
  CHECK_THROWS(istream6 >> reading);

  std::istringstream istream7("4|54");
  istream7 >> reading;
  std::ostringstream ostream;
  CHECK(istream7.fail());
  ostream << Rational(2, 3);
  CHECK(ostream.str() == "2/3");
};
*/