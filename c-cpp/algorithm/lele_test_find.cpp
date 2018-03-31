#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
int main() {
  std::vector<int> vecN;
  for (int i = 0; i < 100; ++i) {
     vecN.push_back(i);
  }

  std::vector<int>::iterator iter = std::find(vecN.begin(), vecN.end(), 50);
  if (iter != vecN.end()) {
    std::cout << "has been found" << std::endl;
  } else {
    std::cout << "has not been found" << std::endl;
  }

  iter = std::find(vecN.begin(), vecN.end(), 150);
  if (iter != vecN.end()) {
    std::cout << "has been found" << std::endl;
  } else {
    std::cout << "has not been found" << std::endl;
  }

  return 0;
}
