#include <iostream>
#include <iostream>

int main() {
  int n;
  int answer;
  std::cin >> n;
  std::string flag = "EASY";
  for (int i = 0; i < n; i++) {
    std::cin >> answer;
    if (answer == 1) {
      flag = "HARD";
    }
  }
  std::cout << flag;
}