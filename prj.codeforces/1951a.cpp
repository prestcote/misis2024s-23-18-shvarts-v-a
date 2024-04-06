#include <iostream>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int c = 0;
    std::cin >> c;
    std::string word = "";
    std::cin >> word;
    if (std::count(word.begin(), word.end(), '1') % 2 == 0) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO";
    }
  }
}