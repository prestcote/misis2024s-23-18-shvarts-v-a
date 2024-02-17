#include <iostream>

int main() {
  int t = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> a >> b >> c;
    if (a == b) {
      std::cout << c << std::endl;
    }
    else if (a == c) {
      std::cout << b << std::endl;
    }
    else {
      std::cout << a << std::endl;
    }
  }
}