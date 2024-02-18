#include <iostream>
#include <cmath>

int main() {
  std::ios::sync_with_stdio(false);
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    __int64 timer = 0;
    __int64 answer = 0;
    std::cin >> n;
    std::cin >> timer;
    __int64 counter = 0;
    while (counter != n) {
      __int64 helper = std::pow(10, counter);
      answer += (timer / helper);
      counter += 1;
    }
    std::cout << answer << std::endl;
  }
}