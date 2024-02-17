#include <iostream> 
#include <vector>
#include <algorithm>

int main() {
  int t = 0;
  int n = 0;
  int number = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::vector <int> vec ;
    std::cin >> n;
    int count = 0;
    for (int j = 0; j < 2 * n; j++) {
      std::cin >> number;
      vec.push_back(number);
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < 2 * n; i+=2) {
      count += std::min(vec[i], vec[i + 1]);
    }
    std::cout << count << std::endl;
  }
}