#include <complex/complex.cpp>
#include <rational/rational.cpp>

#include <vector>
#include <string>

template <class T>
std::vector<T> make_vector() {
  std::vector <T> test{ T(1), T(2), T(3), T(4), T(5), T(6), T(7), T(8), T(9), T(10)};
  return test;
}

template<> 
std::vector<std::string> make_vector() {
  std::vector <std::string> test {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj"};
  return test;
}

template<> 
std::vector<int> make_vector() {
  std::vector <int> test {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  return test;
}