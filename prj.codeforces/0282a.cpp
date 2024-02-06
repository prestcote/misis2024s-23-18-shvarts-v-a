#include <iostream>
#include <string>

int main() {
  int length = 0;
  std::string sentence = "";
  std::cin >> length;
  int X = 0;
  for (int i = 0; i < length; i++) {
    std::cin >> sentence;
    if (sentence == "++X" || sentence == "X++") {
      X += 1;
    }
    else {
      X -= 1;
    }
  }
  std::cout << X << std::endl;
}