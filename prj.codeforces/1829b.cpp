#include <iostream>
#include <algorithm>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::cin >> n;
    int count = 0;
    int max_c = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> c;
      if (c == 0) {
        count += 1;
        max_c = std::max(count, max_c);
      }
      else {
        count = 0;
      }
    }
    std::cout << max_c << std::endl;
  }

}