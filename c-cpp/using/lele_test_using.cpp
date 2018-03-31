#include <iostream>
#include <string>

#define PF std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__ << "]" << std::endl

namespace vacp {

template<typename T1, typename T2 = int>
struct Base {
  Base() { PF; }
  Base(const T1 &t1, const T2 &t2) : type1_value(t1), type2_value(t2) { PF; }
  Base(const T1 &&t1, const T2 &&t2) : type1_value(t1), type2_value(t2) { PF; }
  T1 type1_value;
  T2 type2_value;
  friend std::ostream& operator<<(std::ostream &os, Base &b) {
    os << b.type1_value << " " << b.type2_value;
    return os;
  }
};

}

template<typename T1, typename T2 = int>
using B = vacp::Base<T1, T2>;

int main() {
  B<std::string> b;
  std::cout << b << std::endl;

  B<std::string, double> b1("a", 10);
  std::cout << b1 << std::endl;

  return 0;
}
