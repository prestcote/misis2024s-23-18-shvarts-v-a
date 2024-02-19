#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    int pos = 0;
    int answer = 0;
    std::cin >> n >> pos;
    if (pos < n / 2 + 1) {
      answer = 1;
      while (pos != 1) {
        answer += 2;
        pos -= 1;
      }
    }
    else {
      answer = 0;
      while (pos != 1) {
        answer += 2;
        pos -= 1;
      }
    }
    std::cout << answer << std::endl;
  }
}