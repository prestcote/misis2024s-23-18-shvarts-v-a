#include <iostream>
#include <string>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::string step = "";
    int counter = 0;
    int flag = 0;
    std::cin >> n;
    std::cin >> step;
    for (int j = 0; j < n; j++) {
      if (step[j] == '@' && flag <= 1) {
        flag = 0;
        counter += 1;
      }
      else if (step[j] == '.') {
        if (flag <= 1) {
          flag = 0;
        }
      }
      else if (step[j] == '*') {
        flag += 1;
        if (flag == 2) {
          break;
        }
      }
    }
    std::cout << counter << ' ';
  }
}