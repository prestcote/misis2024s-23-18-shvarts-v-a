#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < 2*n; i++) {
      for (int j = 0; j < 2 * n; j++) {
        if ((i / 2 + j / 2) % 2 == 0) {
          std::cout << '#';
        }
        else {
          std::cout << '.';
        }
      }
      std::cout << std::endl;
    }
  }
}