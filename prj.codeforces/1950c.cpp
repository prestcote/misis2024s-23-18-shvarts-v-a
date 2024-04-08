#include <iostream>
#include <string>


//too tired to do it ngl
int main() {
  int t = 0;
  std::cin >> t;
  std::string time = "";
  for (int i = 0; i < t; i++) {
    std::cin >> time;
    int hh = std::stoi(time.substr(0, 2));
    int mm = std::stoi(time.substr(3, 2));
    if (hh <= 12) {
      std::cout << time << " AM";
    }
    else {

    }
  }
}