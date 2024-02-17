#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  char letter = ' ';
  for (int i = 0; i < t; i++) {
    int a = 0;
    int b = 0;
    int c = 0;
    for (int j = 0; j < 9; j++) {
      std::cin >> letter;
      if (letter == 'A') {
        a += 1;
      }
      else if (letter == 'B') {
        b += 1;
      }
      else if (letter == 'C') {
        c += 1;
      }
    }
    if (a < b && a < c) { std::cout << 'A' << std::endl; }
    else if (b < a && b < c) { std::cout << 'B' << std::endl; }
    else { std::cout << 'C' << std::endl; }
  }
}