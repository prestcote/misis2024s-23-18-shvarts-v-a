#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector <int> places;
  int a = 0;
  int count = 0;
  int r = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a;
    if (i <= k && a > 0) {
      count += 1;
      r = a;
    }
    else if (a == r && a != 0) {
      count += 1;
    }
  }
  std::cout << count;
}