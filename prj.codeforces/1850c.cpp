#include <iostream>
#include <string>

int main() {
  int t = 0;
  char symbol = ' ';
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::string answer = "";
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        std::cin >> symbol;
        if (symbol != '.') {
          answer += symbol;
        }
      }
    }
    std::cout << answer << std::endl;
  }
}