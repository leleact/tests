#include <iostream>
#include <assert.h>
int main() {
  int i = 100;
  std::cout << "i = [" << i << "]" << std::endl;
  assert(i == 2);
  std::cout << "finished" << std::endl;
}
