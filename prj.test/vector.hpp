#include <complex/complex.cpp>
#include <rational/rational.cpp>

#include <vector>
#include <string>

template <class T>
std::vector<T> make_vector() {
  std::vector <T> test{ T(1), T(10), T(20), T(30), T(40) };
  return test;
}

template<> 
std::vector<std::string> make_vector() {
  std::vector <std::string> test {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii"};
  return test;
}

template<> 
std::vector<int> make_vector() {
  std::vector <int> test {1, 2, 3, 4, 5};
  return test;
}