#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  int a = 0;
  int b = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a >> b >> c;

    if (a < b && b < c) {
      std::cout << "STAIR" << std::endl;
    }
    else if (a < b && b > c) {
      std::cout << "PEAK" << std::endl;
    }
    else {
      std::cout << "NONE" << std::endl;
    }
  }
}