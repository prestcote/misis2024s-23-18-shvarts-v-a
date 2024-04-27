#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    int rating = 0;
    std::cin >> rating;
    if (rating <= 1399) {
      std::cout << "Division 4" << std::endl;
    }
    else if (1400 <= rating && rating <= 1599) {
      std::cout << "Division 3" << std::endl;
    }
    else if (1600 <= rating && rating <= 1899) {
      std::cout << "Division 2" << std::endl;
    }
    else {
      std::cout << "Division 1" << std::endl;
    }
  }
}