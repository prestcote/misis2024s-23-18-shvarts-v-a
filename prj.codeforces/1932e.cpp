#include <iostream>
#include <cmath>

int main() {
  std::ios::sync_with_stdio(false);
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    int64_t timer = 0;
    int64_t answer = 0;
    std::cin >> n;
    std::cin >> timer;
    int64_t counter = 0;
    while (counter != n) {
      int64_t helper = std::pow(10, counter);
      answer += (timer / helper);
      counter += 1;
    }
    std::cout << answer << std::endl;
  }
}