#include <iostream>
#include <cstring>
char *mystrstr(const char *, const char *);
int main() {
  char src[] = "bchabckfsk";
  char des[] = "abc";
  char *p = mystrstr(src, des);
  std::cout << p << std::endl;
}

char *mystrstr(const char *src, const char *des) {
  if (src == nullptr)
    return nullptr;
  
  if (des == nullptr)
    return const_cast<char *>(src);

  std::size_t n;
  std::size_t len = strlen(des);
  while(*src++) {
    n = 0;
    for (;*(src + n) == *(des + n) && n <= len; ++n) {
      if (*(des + n + 1) == '\0') 
        return const_cast<char *>(src);
    }
  }

  return nullptr;
}
