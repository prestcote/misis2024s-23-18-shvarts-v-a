#include <iostream>

int main() {
  int n = 0;
  int x = 0;
  int y = 0;
  int z = 0;
  int sum_x = 0;
  int sum_y = 0;
  int sum_z = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x >> y >> z;
    sum_x += x;
    sum_y += y;
    sum_z += z;
  }
  if (sum_x == 0 && sum_y == 0 && sum_z == 0) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }
}