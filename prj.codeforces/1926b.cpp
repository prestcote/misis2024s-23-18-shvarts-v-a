#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    std::string field = "";
    std::string answer = "";
    int counter = 0;
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      std::cin >> field;
      if (std::count(field.begin(), field.end(), '1') != 0) {
        if (counter == 0) {
          counter = std::count(field.begin(), field.end(), '1');
        }
        else {
          if (std::count(field.begin(), field.end(), '1') == counter) {
            answer = "SQUARE";
          }
          else {
            answer = "TRIANGLE";
          }
          
        }
      }
    }
    std::cout << answer << std::endl;
  }
}