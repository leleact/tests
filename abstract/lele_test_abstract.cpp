#include <iostream>
class X {
  virtual	void f() = 0;
  virtual	void g() = 0;
	int i;
};

class Y : X {
  void f() {};
};


int main() {
  Y y;	
}
