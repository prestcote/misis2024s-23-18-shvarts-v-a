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
    if (hh < 12 && hh > 0) {
      std::cout << time << " AM";
    }
    else if (hh == 0) {
      std::cout << ("12:" + time.substr(3, 2) + " AM");
    }
    else if (hh == 12) {
      std::cout << ("12:" + time.substr(3, 2) + " PM");
    }
    else {
      if ((hh - 12) < 10 && (hh - 12) > 0) {
        std::cout << ('0') << (hh - 12)  << (':' + time.substr(3, 2) + " PM");
      }
      else {
        std::cout << hh - 12 <<  (':' + time.substr(3, 2) + " PM");
      }
    }
    std::cout << std::endl;
  }
}