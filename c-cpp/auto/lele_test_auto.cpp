#include <iostream>
#include <vector>
#include <tuple>
#include <typeinfo>

using namespace std;
template<typename T>
struct X {
  T type_value;
  vector<T> t_vec{10};
  auto fun() -> decltype(*t_vec.begin()){
    auto iter = t_vec.begin();
    return *iter;
  }
};

auto getTup() {
    return tuple<string, int, string>("a", 'c', "d");
}

int main(int argc, char *argv[]) {
  vector<string> svec{10};
  auto iter = svec.begin();
  X<int> x;

  cout << x.fun() << endl;
  cout << typeid(getTup()).name() << endl;
  return 0;
}
