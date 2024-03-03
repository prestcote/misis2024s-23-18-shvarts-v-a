#include <iostream>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  std::string cards = "";
  for (int j = 0; j < n; ++j) {
    std::cin >> cards;
    if (cards[0] == 'a' || cards[1] == 'b' || cards[2] == 'c') {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
}