#include <iostream>
#include <vector>
#include <algorithm>

// I WENT INSANE AND NEVER FINISHED IT SORRY IM GONNA DO IT LATER
// i mean its almost working it passes like 60 tests...!!!

int main() {
  int n = 0;
  std::cin >> n;
  std::vector <int> people(5);
  int g = 0;
  int ost = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> g;
    people[g] += 1;
    ost += g;
  }
  int count = 0;
  //std::cout << count << ' ' << people[1] << people[2] << people[3] << people[4] << std::endl;
  count += people[4];
  people[4] = 0;
  //std::cout << count << ' ' << people[1] << people[2] << people[3] << people[4] << std::endl;
  count += std::min(people[3], people[1]);
  int bruh = std::min(people[3], people[1]);
  people[3] -= bruh;
  people[1] -= bruh;
  //std::cout << count << ' ' << people[1] << people[2] << people[3] << people[4] << std::endl;
  if (people[3] != 0) {
    count += people[3];
    people[3] = 0;
  }
  //std::cout << count << ' ' << people[1] << people[2] << people[3] << people[4] << std::endl;
  count += people[2] / 2;
  people[2] -= (people[2] / 2) * 2;
  //std::cout << count << ' ' << people[1] << people[2] << people[3] << people[4] << std::endl;
  count += people[1] / 4;
  people[1] -= (people[1] / 4) * 4;
  //std::cout << count << ' ' << people[1] << people[2] << people[3] << people[4] << std::endl;
  if (people[1] + people[2] > 4) {
    count += 2;
  }
  else if (people[1] + people[2] < 4 && people[1] + people[2] != 0) { count += 1; }
  //std::cout << count << ' ' << people[1] << people[2] << people[3] << people[4] << std::endl;
  std::cout << count;
}
