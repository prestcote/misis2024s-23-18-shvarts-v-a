#include <iostream>

int main() {
  int t = 0;
  for (int i = 0; i < t; i++) {
    int n = 0; 
    int m = 0;
    if ((n >= m) && (n % 2 == m % 2)) {
      std::cout << "YES";
    }
    else {
      std::cout << "NO";
    }
  }
}