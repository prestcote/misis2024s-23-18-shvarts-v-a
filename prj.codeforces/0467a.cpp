#include <iostream> 

int main() {
  int n = 0;
  int capacity = 0;
  int busy = 0;
  int answer = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> busy >> capacity;
    if (capacity - busy > 1) {
      answer += 1;
    }
  }
  std::cout << answer;
}