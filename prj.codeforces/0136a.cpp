#include <iostream> 
#include <vector>

int main() {
  int n = 0;
  int frnd = 0;
  std::cin >> n;
  std::vector <int> list(n+1);
  for (int i = 1; i < n+1; i++) {
    std::cin >> frnd;
    list[frnd] = i;
  }
  for (int i = 1; i < n + 1; i++) {
    std::cout << list[i] << " ";
  }
}