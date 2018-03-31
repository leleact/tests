#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, int> test_map;

  std::string s1 = "aaa";
  std::string s2 = "aaa";

  test_map.insert(make_pair(s1, 1));
  test_map.insert(make_pair(s2, 2));

  test_map["vvv"] = 12;

  std::size_t n = test_map.erase("bbbb");
  std::cout << "n=[" << n << "]" << std::endl;


  std::map<std::string, int>::iterator iter = test_map.begin();
  while (iter != test_map.end()) {
    std::cout << iter->first << ", " << iter->second << std::endl; 
    iter++;
  }
}
