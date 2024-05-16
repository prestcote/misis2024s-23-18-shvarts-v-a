#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n = 0;
    std::cin >> n;
    int mult = 1;
    int min_n = INT32_MIN;
    bool ZERO = false;
    for (int j = 0; j < n; ++j) {
      int x = 0;
      std::cin >> x;
      if (x == 0 && ZERO == false) {
        mult *= 1;
        ZERO = true;
      }
      else {
        mult *= x;
      }
      if (x < min_n) {
        min_n = x;
      }
    }
    if (min_n == 0) {
      std::cout << mult << std::endl;
    }
    else {
      std::cout << ((mult / min_n) * (min_n + 1)) << std::endl;
    }
  }
}