#include <iostream>
#include <string>
#include <vector>
#include <cstring>

int main() {
  std::vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }

  std::vector<int>::iterator iter = vec.begin();
  /*
  for (; iter != vec.end();) {
    if (*iter == 6) {
      std::cout << *iter << std::endl; 
      std::vector<int>::iterator iter1 = vec.erase(iter);
      std::cout << *iter << std::endl; 
      std::cout << *iter1 << std::endl; 
    }
    else
      iter++;
  }
  */

  /* 死循环 */
  for (; iter != vec.end(); ) {
    std::cout << *iter << " ";
    vec.insert(iter, 40);
    std::cout << *iter << " ";
    iter++;
    std::cout << *iter << " ";
    ++iter;
    std::cout << *iter << std::endl;
  }

  for (iter = vec.begin(); iter != vec.end(); ++iter)
    std::cout << *iter << " ";
  std::cout << std::endl;
}

