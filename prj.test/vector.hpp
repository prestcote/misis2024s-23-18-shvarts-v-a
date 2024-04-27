#include <complex/complex.cpp>
#include <rational/rational.cpp>

#include <vector>
#include <string>

template <class T>
void make_vector(int size, std::vector<T>& data) {
  data.clear();
  data.reserve(size);
  for (int i = 1; i < size+1; i++) {
    data.emplace_back(T(i));
  }
}

template<> 
void make_vector(int size, std::vector<std::string>& data) {
  data.clear();
  data.reserve(size);
  for (int i = 1; i < size + 1; i++) {
    data.emplace_back(std::to_string(i));
  }
}

template<> 
void make_vector(int size, std::vector<int>& data) {
  data.clear();
  data.reserve(size);
  for (int i = 1; i < size + 1; i++) {
    data.emplace_back(i);
  }
}