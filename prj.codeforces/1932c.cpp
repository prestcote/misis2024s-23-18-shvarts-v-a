#include <iostream>
#include <vector>
#include <string>

int main() {
  int t = 0;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    int n = 0;
    long long m = 0;
    int element = 0;
    std::vector <int> numbers;
    std::string instruct = "";
    long long product = 1;
    std::cin >> n >> m;
    for (int j = 0; j < n; j++) {
      std::cin >> element;
      product *= element;
      //std::cout << product << ' ';
      numbers.push_back(element);
    }
    std::cin >> instruct;
    int counter = 0;
    while (numbers.size() != 0) {
      std::cout << product << ' ' << (product % m) << std::endl;
      if (instruct[counter] == 'L') {
        //std::cout << numbers[0] << ' ';
        product /= numbers[0];
        numbers.erase(numbers.begin());
        //numbers = numbers[1, n - counter];
      }
      else {
        std::cout << numbers[n - 1 - counter];
        product /= numbers[numbers.size() - 1];
        numbers.pop_back();
      }
      counter += 1;
    }
    std::cout << std::endl;
  }
}