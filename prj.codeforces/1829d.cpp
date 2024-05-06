#include <iostream>

bool nuggets(int n, int m) {
  if (n == m) {
    return true;
  }
  else if (m > n ||  n % 3 != 0) {
    return false;
  }
  else {
    return (nuggets(n / 3, m) || nuggets((2 * n) / 3, m));
  }
}

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    if (nuggets(n, m) == true) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
}