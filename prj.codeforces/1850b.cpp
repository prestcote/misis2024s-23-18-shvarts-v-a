#include <iostream>

int main() {
  int t = 0;
  int n = 0;
  int a = 0;
  int b = 0;
  int answer = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    int max_b = -1;
    for (int j = 1; j <= n; j++) {
      std::cin >> a >> b;
      if (a <= 10 && b >= max_b) {
        max_b = b;
        answer = j;
      }
    }
    std::cout << answer << std::endl;
  }
}