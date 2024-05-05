#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::cin >> n;
    long long count = 0;
    for (int j = 0; j < n; j++) {
      std::string word1 = "";
      std::cin >> word1;
      for (int k = j + 1; k < n; k++) {
        std::string word2 = "";
        std::cin >> word2;
        if ((word1[0] == word2[0]) && (word1[1] != word2[1]) || (word1[1] == word2[1]) && (word1[0] != word2[0])) {
          count += 1;
        }
      }
    }
    std::cout << count;
  }
}