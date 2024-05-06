#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::cin >> n;
    int max = -1;
    for (int j = 0; j < n; j++) {
      char s = ' ';
      std::cin >> s;
      if (s - 'a' + 1 > max) {
        max = (s - 'a' + 1);
      }
    }
    std::cout << max << std::endl;
  }
}