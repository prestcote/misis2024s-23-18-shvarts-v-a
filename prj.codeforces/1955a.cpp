#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  int n = 0;
  int a = 0;
  int b = 0;
  for (int i = 0; i < t; i++) {
    std::cin >> n >> a >> b;
    if (a * 2 < b) {
      std::cout << (n * a) << std::endl;
    }
    else {
      std::cout << ((n / 2) * b + (n % 2) * a) << std::endl;
    }
  }
}