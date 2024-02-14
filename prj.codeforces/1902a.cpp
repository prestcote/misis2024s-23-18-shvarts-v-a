#include <iostream>
#include <algorithm>
#include <string>

int main() {
  int t = 0;
  int n = 0;
  std::string symbols;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    std::cin >> symbols;
    if (std::count(symbols.begin(), symbols.end(), '0') > 0) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }

}