#include <iostream>
#include <algorithm>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n = 0;
    std::cin >> n;
    int summ = 0;
    int element = 0;
    for (int j = 0; j < n; ++j) {
      std::cin >> element;
      summ += std::abs(element);
    }
    std::cout << summ << std::endl;
  }
}