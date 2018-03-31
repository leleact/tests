#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
void LeleTestLambda();
int main(int argc, char *argv[]) {
  LeleTestLambda();
  return 0;
}

/// Lambda expression
/// [capture list] (parameter list) -> return type {function body}
void LeleTestLambda() {
  {
    auto f = [] { return 42; };
    std::cout << f() << std::endl; 
  }

  {
    std::vector<std::string> words;
    words.push_back("aaaa");
    words.push_back("bbbb");
    words.push_back("ccc");
    words.push_back("ddccc");
    std::for_each(words.begin(), words.end(), [](const std::string &it){ std::cout << it << std::endl; });
    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b){ return a.size() < b.size(); }); 
    std::for_each(words.begin(), words.end(), [](const std::string &it){ std::cout << it << std::endl; });
  }
}
