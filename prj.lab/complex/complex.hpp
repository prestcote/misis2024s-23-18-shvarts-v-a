#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX_HPP
#include <sstream>

struct Complex {
  double re{ 0.0 };
  double im{ 0.0 };

  Complex();
  Complex(double re, double im);
  Complex(const Complex& c) = default; 
  Complex(Complex&&) = default;
  explicit Complex(const double re);
  ~Complex() = default;

  std::ostream& WriteTo(std::ostream& ostrm) const noexcept; 
  std::istream& ReadFrom(std::istream& istrm) noexcept; 

  Complex& operator=(const Complex& c);
  Complex& operator=(Complex&&) = default;
  Complex operator-() const noexcept;

  Complex& operator+=(const Complex& rhs);
  Complex& operator-=(const Complex& rhs);
  Complex& operator*=(const Complex& rhs);
  Complex& operator/=(const Complex& rhs);

  Complex& operator+=(const double rhs); 
  Complex& operator-=(const double rhs);
  Complex& operator*=(const double rhs);
  Complex& operator/=(const double rhs);

  bool operator==(const Complex& lhs) const noexcept;
  bool operator!=(const Complex& lhs) const noexcept;

  static const char leftBrace{ '{' };
  static const char separator{ ',' };
  static const char rightBrace{ '}' };
};
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

Complex operator+(const Complex& lhs, const double rhs); 
Complex operator-(const Complex& lhs, const double rhs); 
Complex operator*(const Complex& lhs, const double rhs); 
Complex operator/(const Complex& lhs, const double rhs); 

Complex operator-(const double lhs, const Complex& rhs); 
Complex operator+(const double lhs, const Complex& rhs); 
Complex operator*(const double lhs, const Complex& rhs); 
Complex operator/(const double lhs, const Complex& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);



#endif