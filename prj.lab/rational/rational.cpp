#include <rational/rational.hpp>

#include <iostream>
#include <sstream>

Rational::Rational(const std::int64_t& num, const std::int64_t& den) {
  if (den == 0) {
    throw std::invalid_argument("Division by zero exception");
  }
  if (den < 0) {
    num_ = -num / nod(num, den);
    den_ = -den / nod(num, den);
  }
  else {
    num_ = num / nod(num, den);
    den_ = den / nod(num, den);
  }
};

Rational& Rational::operator+=(const Rational& rhs) noexcept {
  int64_t num = num_;
  int64_t den = den_;
  num_ = num * rhs.den_ + den * rhs.num_;
  den_ = den * rhs.den_;
  invrnt();
  return *this;
}

Rational& Rational::operator+=(const int64_t rhs) noexcept {
  *this += Rational(rhs);
  invrnt();
  return *this;
}
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  Rational res(lhs);
  res += rhs;
  return res;
}
Rational operator+ (const int64_t lhs, const Rational& rhs) noexcept {
  Rational sum(lhs);
  sum += rhs;
  return sum;
}
Rational operator+ (const Rational& lhs, const int64_t rhs) noexcept {
  Rational sum(lhs);
  sum += rhs;
  return sum;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  invrnt();
  return *this;
}
Rational& Rational::operator-=(const int64_t rhs) noexcept {
  *this -= Rational(rhs);
  invrnt();
  return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
  Rational res(lhs);
  res -= rhs;
  return res;
}
Rational operator-(const Rational& lhs, const int64_t rhs) noexcept {
  Rational res(lhs);
  res -= rhs;
  return res;
}
Rational operator-(const int64_t lhs, const Rational& rhs) noexcept {
  Rational res(lhs);
  res -= rhs;
  return res;
}

Rational& Rational::operator*= (const Rational& rhs) noexcept {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  invrnt();
  return *this;
}
Rational& Rational::operator*=(const int64_t rhs) noexcept { //HELLO????
  *this *= Rational(rhs);
  invrnt();
  return *this;
}
Rational operator* (const Rational& lhs, const Rational& rhs) noexcept {
  Rational res(lhs);
  res *= rhs;
  return res;
}
Rational operator*(const Rational& lhs, const int64_t rhs)  noexcept { //DOIT
  Rational mult(lhs);
  mult *= rhs;
  return mult;
}
Rational operator*(const int64_t lhs, const Rational& rhs) noexcept { //DOIT
  Rational mult(lhs);
  mult *= rhs;
  return mult;
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.num_ == 0) {
    throw std::invalid_argument("Divide by zero exception");
  }
  num_ *= rhs.den_;
  den_ *= rhs.num_;
  invrnt();
  return *this;
}

Rational& Rational::operator/=(const int64_t rhs) { //DOIT
  //if (rhs == 0) {
    //throw std::invalid_argument("Divide by zero exception");
  //}
    *this /= Rational(rhs);
  return *this;;
}
Rational operator/ (const Rational& lhs, const Rational& rhs) { //DOIT
  Rational res(lhs);
  res /= rhs;
  return res;
}
Rational operator/ (const Rational& lhs, const int64_t rhs) { //DOIT
  Rational res(lhs);
  res /= rhs;
  return res;
}
Rational operator/(const int64_t lhs, const Rational& rhs) { //DOIT
  Rational res(lhs);
  res /= rhs;
  return res;
}

bool Rational::operator== (const Rational& rhs) const noexcept{
  return num_ == rhs.num_ && den_ == rhs.den_;
}

bool Rational::operator!=(const Rational& rhs) const noexcept {
  return !(*this == rhs);
}

bool Rational::operator<(const Rational& rhs) const noexcept {
  return (num_ * rhs.den_) < (rhs.num_ * den_);
}
bool Rational::operator<=(const Rational& rhs) const noexcept {
  return *this == rhs || *this < rhs;
}
bool Rational::operator>(const Rational& rhs) const noexcept {
  return !(*this < rhs);
}
bool Rational::operator>= (const Rational& rhs) const noexcept{
  return *this == rhs || *this > rhs;
}

Rational& Rational::reduce(Rational& c) const {
  int a = c.num_;
  int b = c.den_;
  if (a < 0) { a = -a; }
  if (b < 0) { b = -b; }
  if (a < b) {
    std::swap(a, b);
  }
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  c.num_ = c.num_ / a;
  c.den_ = c.den_ / a;
  return c;
}

void Rational::invrnt() {
  auto ans = nod(std::abs(num_), std::abs(den_));
  if (den_ < 0) {
    num_ *= (-1);
    den_ *= (-1);
  }
  num_ /= ans;
  den_ /= ans;
}

int64_t Rational::nod(int64_t a, int64_t b) const {
  if (a < 0) { a = -a; }
  if (b < 0) { b = -b; }
  if (a < b) {
    std::swap(a, b);
  }
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

std::istream& Rational::ReadFrom (std::istream& istrm) noexcept {
  char separator(0);
  int64_t num(0);
  int64_t den(1);
  char check = istrm.peek();
  istrm >> num;
  char check1 = istrm.peek();
  if (!istrm || check1 != '/') {
    istrm.setstate(std::ios_base::failbit);
    return istrm;
  }
  istrm >> separator;
  int64_t check2 = istrm.peek();
  istrm >> den;
  if (!istrm || check2 > '9' || check2 < '0') {
    istrm.setstate(std::ios_base::failbit);
    return istrm;
  }
  else {
    if (Rational::separator == separator && den > 0) {
      *this = Rational(num, den);
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
  ostrm << num_ << separator << den_;
  return ostrm;
}

std::istream& operator>> (std::istream& istrm, Rational& rhs) noexcept {
  return rhs.ReadFrom(istrm);
}
std::ostream& operator<<(std::ostream& ostrm, Rational& rhs) noexcept {
  return rhs.WriteTo(ostrm);
}