#include <iostream>
#include <vector>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::vector <int> vec;
    int n = 0;
    std::cin >> n;
    int flag = 1;
    int el = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> el;
      vec.push_back(el);
    }
    if (n > 2) {
      for (int i = 0; i < n - 2; i++) {
        if (!(vec[i] % 2 == vec[i + 2] % 2)) {
          flag = 0;
          break;
        }
      }
    }
    if (flag == 1 || n == 2) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
}