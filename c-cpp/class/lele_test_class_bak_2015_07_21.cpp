#include <iostream>
struct X {
  X() = default;
  X(const X &) = default;
  X(X &&) = default;
  X &operator=(const X &) = default;
  X &operator=(X &&) = default;
  virtual ~X() = default;
};

struct Y : private X {};

class Base {};

class Deried : public Base {
public:
  Deried(const Deried &d) : Base(d) {}
  Deried(Deried &&d) : Base(std::move(d)) {}
  Deried &operator=(const Deried &d) {
    Base::operator=(d);
    return *this;
  }
  Deried &operator=(Deried && d) {
    Base::operator=(std::move(d)); 
    return *this;
  }
private:
};

/*
class Object {
  Object(std::string str) : str(str) {}

private:
  std::string str;
};
*/

class Object {
public:
  Object(std::string str);
  void show();

private:
  std::string str;
};

int main() {
}
