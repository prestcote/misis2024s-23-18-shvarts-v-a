#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::cin >> n;
    std::vector<int> s;
    for (int j = 0; j < n; j++) {
      int number = 0;
      std::cin >> number;
      s.push_back(number);
    }
    std::vector<int> s1 = s;
    std::sort(s1.begin(), s1.end(), std::greater<int>());
    for (int k = 0; k < n; k++) {
      if (s[k] == s1[0]) {
        std::cout << s[k] - s1[1] << ' ';
      }
      else {
        std::cout << s[k] - s1[0] << ' ';
      }
    }
    std::cout << std::endl;
  }
}