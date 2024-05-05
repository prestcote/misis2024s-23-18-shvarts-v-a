#include <iostream>
#include <vector>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    int q = 0;
    std::cin >> n >> q;
    std::vector <int> sum;
    int a = 0;
    std::cin >> a;
    sum.push_back(0);
    sum.push_back(a);
    for (int i = 2; i <= n; i++) {
      std::cin >> a;
      sum.push_back(a + sum[i - 1]);
    }
    for (int j = 0; j < q; j++) {
      int l = 0;
      int r = 0;
      int k = 0;
      std::cin >> l >> r >> k;
     // std::cout << l << r << k;
      long long ans = sum[n] - sum[r] + sum[l - 1] + k * (r - l + 1);
      if (ans % 2 == 0) {
        std::cout << "NO" << std::endl;
      }
      else {
        std::cout << "YES" << std::endl;
      }
    }
  }
}