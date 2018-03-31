#include <iostream>
int main(int argc, char **argv) {
  const int i = 100;
  decltype(i) a = 10; // Type i is const int

  return 0;
}
