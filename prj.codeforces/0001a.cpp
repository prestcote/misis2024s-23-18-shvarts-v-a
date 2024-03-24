#include <iostream>

int main() {
  long long n = 0;
  long long m = 0;
  long long a = 0;
  long long res = 1;
  std::cin >> n >> m >> a;
  if (n % a == 0) {
    res *= (n / a);
  }
  else {
    res *= (n / a + 1);
  }
  if (m % a == 0) {
    res *= (m / a);
  }
  else {
    res *= (m / a + 1);
  }
  std::cout << res;
}