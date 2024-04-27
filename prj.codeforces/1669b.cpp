#include <iostream>
#include <map>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::map <int, int> map;
    int n = 0;
    std::cin >> n;
    int v = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> v;
      map[v] += 1;
    }
    int flag = 0;
    for (const auto& value : map) {
      if (value.second >= 3) {
        std::cout << value.first << std::endl;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      std::cout << -1 << std::endl;
    }
  }
}