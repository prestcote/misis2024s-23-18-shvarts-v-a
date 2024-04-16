#include <iostream>
#include <string>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    long long a = 0;
    long long min_10 = 4 * 10000000000;
    long long min_01 = 4 * 10000000000;
    long long min_11 = 4 * 10000000000;
    std::string b = "";
    int n = 0;
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      std::cin >> a >> b;
      if (b == "01" && a < min_01) {
        min_01 = a;
      }
      else if (b == "10" && a < min_10) {
        min_10 = a;
      }
      else if (b == "11" && a < min_11) {
        min_11 = a;
      }
    }
    if (std::min(min_11, min_10 + min_01) >= 4 * 10000000000) {
      std::cout << -1 << std::endl;
    }
    else {
      std::cout << std::min(min_11, min_10 + min_01) << std::endl;
    }
  }

}