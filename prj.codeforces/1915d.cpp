#include <iostream>
#include <string>
#include <algorithm>

int main() {
  int t = 0;
  int n = 0;
  std::string word = "";
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    std::cin >> word;
    std::string answer = "";
    while (n != 0) {
      if (word[n-1] == 'b' || word[n-1] == 'c' || word[n-1] == 'd') {
        if (n - 3 != 0) {
          answer = "." + word[n - 3, n-1] + answer;
          std::cout << answer << " " << word[n-3, n-1] << std::endl;
        }
        n -= 3;
      }
      if (word[n - 1] == 'a' || word[n - 1] == 'e') {
        if (n - 2 != 0) {
          answer = answer + "." + word[n - 2, n];
        }
        n -= 2;
      }
    }
    //std::reverse(answer.begin(), answer.end());
    std::cout << answer << std::endl;
  }
}