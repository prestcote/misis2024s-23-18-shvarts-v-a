#include <iostream>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  std::string word = "";
  for (int i = 0; i < n; i++) {
    std::cin >> word;
    if (word.find("it") != std::string::npos) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
}