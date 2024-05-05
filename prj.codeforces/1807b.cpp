#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::cin >> n;
    int even = 0;
    int odd = 0;
    int number = 0;
    for (int j = 0; j < n; j++) {
      std::cin >> number;
      if (number % 2 == 0) {
        even += number;
      }
      else {
        odd += number;
      }
    }
    if (even > odd) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
}