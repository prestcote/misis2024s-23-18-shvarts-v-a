#ifndef RATIONAL_RATIONAL_HPP
#define RATIONAL_RATIONAL_HPP

#include <iostream>
#include <stdexcept>
#include <iosfwd>

class Rational {
public:
  Rational() = default;
  explicit Rational(const std::int64_t n_num) : num_{ n_num }, den_{ 1 } {};
  Rational(const std::int64_t& num_, const std::int64_t& den_);
  ~Rational() = default;
  Rational(const Rational& x) = default; //копирование

  Rational& operator=(const Rational&) = default;
  Rational operator-() const noexcept { return { -num_, den_ }; }

  Rational& operator+=(const Rational& rhs) noexcept;
  Rational& operator-=(const Rational& rhs) noexcept;
  Rational& operator*=(const Rational& rhs) noexcept;
  Rational& operator/=(const Rational& rhs);

  Rational& operator+=(const int64_t rhs) noexcept;
  Rational& operator-=(const int64_t rhs) noexcept;
  Rational& operator*=(const int64_t rhs) noexcept;
  Rational& operator/=(const int64_t rhs);

  int64_t num() const noexcept { return num_; }
  int64_t den() const noexcept { return den_; }

  bool operator==(const Rational& rhs) const noexcept; //CONST!!!!!!!! REMAKE!!!!!!!!!!!!!!!
  bool operator!=(const Rational& rhs) const noexcept; //CONST!!!!!!!!
  bool operator<(const Rational& rhs) const noexcept; //CONST!!!!!!!!
  bool operator<=(const Rational& rhs) const noexcept; //CONST!!!!!!!!
  bool operator>(const Rational& rhs) const noexcept; //CONST!!!!!!!!
  bool operator>=(const Rational& rhs) const noexcept; //CONST!!!!!!!!

  //friend std::ostream& operator<< (std::ostream& stream, const Rational& rhs);
  //friend std::istream& operator>> (std::istream& stream, Rational& rhs);

  std::istream& ReadFrom(std::istream& istrm) noexcept;
  std::ostream& WriteTo(std::ostream& ostrm) const noexcept;

  static const char separator{ '/' };
private:
  std::int64_t num_ = 0;
  std::int64_t den_ = 1;

  Rational& reduce(Rational& c) const;
  int64_t nod(int64_t a, int64_t b) const;
  void invrnt();
};

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator/(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator-(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator*(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator/(const Rational& lhs, const int64_t rhs);

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept;
Rational operator-(const int64_t lhs, const Rational& rhs) noexcept;
Rational operator*(const int64_t lhs, const Rational& rhs) noexcept;
Rational operator/(const int64_t lhs, const Rational& rhs);

//inline std::istream& operator>> (std::istream& istrm, Rational& rhs);

std::istream& operator>> (std::istream& istrm, Rational& rhs) noexcept;
std::ostream& operator<< (std::ostream& ostrm, Rational& rhs) noexcept;

#endif