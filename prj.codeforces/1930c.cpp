#include <iostream> 
#include <vector>
#include <set>
#include <cstdlib>
#include <vector>
#include <algorithm>


int main() {
  int t = 0;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    int n = 0;
    std::set <int> S;
    std::set<int>::iterator ik;
    std::vector <int> a;
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        int number = 0;
        std::cin >> number;
        a.push_back(number);
      }
      while (a.size() != 0) {
        for (int k = 0; k < n; k++) {
          if (a[i] == *std::max_element(a.begin(), a.end())) {
            S.insert(a[i] + i);
            a.erase(a.begin() + i);
          }
        }
      }
      std::vector<int> vc(S.size());
      copy(S.begin(), S.end(), vc.begin());
      for (int i = 0; i < vc.size(); i++) {
        std::cout << vc[i] << ' ';
      }
      std::cout << std::endl;
    }
  }
}