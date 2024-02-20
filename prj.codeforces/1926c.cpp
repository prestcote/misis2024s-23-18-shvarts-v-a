#include <iostream>
#include <vector>

int pos(int x) {
  int res = 0;
  while (x != 0) {
    res += (x % 10);
    x /= 10;
  }
  return res;

}


int main() {
  int t = 0;
  int max_n = 2 * 100000 + 5;
  std::vector <int> vec (2*100000+5);
  vec[0] = 0;
  for (int i = 1; i < max_n; i++) {
    vec[i] = vec[i - 1] + pos(i);
  }
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::cin >> n;
    std::cout << vec[n] << ' ';
  }
}