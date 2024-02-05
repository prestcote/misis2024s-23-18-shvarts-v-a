#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <complex/complex.hpp>

Complex::Complex() : re(0), im(0) {};
Complex::Complex(double re, double im) : re(re), im(im) {};
Complex::Complex(double re) : re(re), im(0) {};

Complex& Complex::operator+=(const Complex& rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}
Complex& Complex::operator+=(const double rhs) {
  re += rhs;
  return *this;
}

Complex& operator+(const Complex& lhs, const Complex& rhs) {
  Complex sum(lhs);
  sum += rhs;
  return sum;
}
Complex& operator+(const Complex& lhs, const double rhs){
  Complex sum(lhs);
  sum += rhs;
  return sum;
}
Complex& operator+(const double lhs, const Complex& rhs){
  Complex sum(lhs);
  sum += rhs;
  return sum;
}

Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}
Complex& Complex::operator-= (const double rhs) {
  re -= rhs;
  return *this;
}
Complex& operator-(const Complex& lhs, const Complex& rhs) {
  Complex subs(lhs);
  subs -= rhs;
  return subs;
}
Complex& operator-(const Complex& lhs, const double rhs){
  Complex subs(lhs);
  subs -= rhs;
  return subs;
}

Complex& operator-(const double lhs, const Complex& rhs){
  Complex subs(lhs);
  subs -= rhs;
  return subs;
}

Complex& Complex::operator*=(const Complex& rhs) {
  Complex Mult;
  Mult.re = re * rhs.re - im * rhs.im;
  Mult.im = re * rhs.im + rhs.re * im;
  *this = Mult;
  return *this;
}
Complex& Complex::operator*=(const double rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex& operator*(const Complex& lhs, const Complex& rhs) {
  Complex mult(lhs);
  mult *= rhs;
  return mult;
}
Complex& operator*(const Complex& lhs, const double rhs){
  Complex Mult(lhs);
  Mult *= rhs;
  return Mult;
}
Complex& operator* (const double lhs, const Complex& rhs){
  Complex Mult(rhs);
  Mult *= lhs;
  return Mult;
}

Complex& Complex::operator/=(const Complex& rhs) {
  Complex Div;
  double r = rhs.re * rhs.re + rhs.im * rhs.im;
  if (r == 0) {
    throw std::invalid_argument("DivisionByZeroException");
  }
  Div.re = (re * rhs.re + im * rhs.im) / r;
  Div.im = (im * rhs.re - re * rhs.im) / r;
  *this = Div;
  return *this;
}
Complex& Complex::operator/=(const double rhs) {
  if (rhs == 0) {
    throw std::invalid_argument("DivisionByZeroException"); //EXCEPTION!!!!!!!!!!!!!!!!!!!!!!!!
  }
  re /= rhs;
  im /= rhs;
  return *this;
}
Complex& operator/(const Complex& lhs, const Complex& rhs) {
  Complex div(lhs);
  div /= rhs;
  return div;
}

Complex& operator/(const Complex& lhs, const double rhs) {
  Complex div(lhs);
  div /= rhs;
  return div;
}

Complex& operator/(const double lhs, const Complex& rhs) {
  Complex div(lhs);
  div /= rhs;
  return div;
}

bool Complex::operator== (const Complex& rhs) const noexcept {
  return std::abs(re - rhs.re) <= 2 * DBL_EPSILON && std::abs(im - rhs.im) <= 2 * DBL_EPSILON;
}

bool Complex::operator!= (const Complex& rhs) const noexcept {
  return !(*this == rhs);
}
Complex& Complex::operator=(const Complex& c) {
  re = c.re;
  im = c.im;
  return *this;
}
Complex& Complex::operator-(){
  Complex sub = *this;
  sub.re = -re;
  sub.im = -im;
  return sub;
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  ostrm << rhs.leftBrace << rhs.re << rhs.separator << rhs.im << rhs.rightBrace;
  return ostrm;
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  char leftBrace(0);
  double real(0.0);
  char comma(0);
  double imaganary(0.0);
  char rightBrace(0);
  istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
  if (!istrm.good()) {
    return istrm;
  }
  if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace))
  {
    rhs.re = real;
    rhs.im = imaganary;
  }
  else
  {
    istrm.setstate(std::ios_base::failbit);
  }
  return istrm;
}

Complex Complex::conjugate(){
  Complex conj = *this;
  conj.im = -conj.im;
  return conj;
}

