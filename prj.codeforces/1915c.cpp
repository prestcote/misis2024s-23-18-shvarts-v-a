#include <iostream>
#include <cmath>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    int number = 0;
    long long counter = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cin >> number;
      counter += number;
    }
    if ((int)std::sqrt(counter) == std::sqrt(counter)) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
}