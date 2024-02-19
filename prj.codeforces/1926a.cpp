#include <iostream>
#include <algorithm>
#include <string>

int main() {
  int t = 0;
  std::string letters = "";
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> letters;
    int a = std::count(letters.begin(), letters.end(), 'A');
    int b = std::count(letters.begin(), letters.end(), 'B');
    if (a > b) {
      std::cout << 'A' << std::endl;
    }
    else {
      std::cout << 'B' << std::endl;
    }
  }
}