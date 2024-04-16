#include <iostream>
#include <string>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::string word = "";
    std::cin >> word;
    std::string cf = "codeforces";
    int count = 0;
    for (int i = 0; i < 10; i++) {
      if (word[i] != cf[i]) {
        count += 1;
      }
    }
    std::cout << count << std::endl;
  }
}