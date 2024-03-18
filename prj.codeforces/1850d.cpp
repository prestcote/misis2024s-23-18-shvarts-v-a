#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    int k = 0;
    std::vector<int>problems;
    std::cin >> n >> k;
    for (int j = 0; j < n; j++) {
      int n1 = 0;
      std::cin >> n1;
      problems.push_back(n1);
    }
    std::sort(problems.begin(), problems.end());
    int counter = 1;
    int max_counter = -1;
    for (int c = 1; c < n; c++) {
      if (std::abs(problems[c] - problems[c - 1]) <= k) {
        counter += 1;
      }
      else {
        max_counter = std::max(max_counter, counter);
        counter = 1;
      }
    }
    max_counter = std::max(max_counter, counter);
    std::cout << (n - max_counter) << std::endl;
  }
}