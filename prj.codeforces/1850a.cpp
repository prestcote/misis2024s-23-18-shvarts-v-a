#include <iostream>

int main() {
  int t = 0;
  int a = 0; 
  int b = 0;
  int c = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> a >> b >> c;
    if (a + b >= 10 || a + c >= 10 || b + c >= 10) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
}