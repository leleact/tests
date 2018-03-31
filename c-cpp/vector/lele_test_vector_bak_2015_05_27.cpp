#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
class MyString {
public:
  MyString():data(new char[16]) {
    cout << "default constructor" << endl;;
    memset(data, 0x00, sizeof(*data));
  };

  MyString(const char *pchar) : data(new char[strlen(pchar) + 1]) {
    cout << "constructor const char *" << endl;
    strcpy(data, pchar);
  }

  MyString(const MyString &s) : data(new char[s.size() + 1]) {
    cout << "constuctor const MyString &" << endl;
    strcpy(data, s.c_str());
  }

  MyString &operator=(const MyString &s) {
    cout << "operator = MyString"  << endl;
    if (this != &s) {
      if (this->size() != s.size()) {
        delete[] data; 
        this->data = new char[s.size() + 1];
        strcpy(data, s.c_str());
      } else {
        strcpy(data, s.c_str());
      }
    }
    return *this;
  }

  MyString &operator=(const char *pchar) {
    cout << "operator = const char *"  << endl;
    if (this->size() != strlen(pchar)) {
      delete[] data; 
      this->data = new char[strlen(pchar) + 1];
      strcpy(data, pchar);
    } else {
      strcpy(data, pchar);
    }
    return *this;
  }

  size_t size() const {
    return strlen(data);
  }

  const char *c_str() const {
    return data; 
  }

  ~MyString() {
    cout << "destructor" << endl;;
    delete[] data; 
    data = nullptr;
  }

  friend ostream &operator << (ostream &os, MyString &s) {
    os << s.c_str(); 
    return os;
  }

private:
  char *data;
};

int InitVectorTest();
template<typename T>
int ShowVectorElement(vector<T> &);
int MyStringTest();

int main() {
//  InitVectorTest();
  MyStringTest();
}

int MyStringTest() {
/*
  MyString s1 = "a";
  cout << "=======================================" << endl;
  MyString s2 = s1;
  cout << "=======================================" << endl;

  MyString s3;
  MyString s4;
  s3 = "bb";
  s4 = s3;

  cout << "=======================================" << endl;
*/

  vector<MyString> svec{"a", "b", "c"};
  ShowVectorElement(svec);
  return 0;
}

template<typename T>
int ShowVectorElement(vector<T> &vec) {
  for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << " "; 
  }

  cout << "size : " << vec.size();
  cout << endl;

  return 0;
}

int InitVectorTest() {
  vector<int> ivec;
  vector<MyString> MyString_vec;
  vector<vector<string>> file;
  vector<int> ivec2(ivec);
  vector<int> ivec3 = ivec;
  vector<string> articles = {"a", "an", "the"};
  vector<int> ivec4(10, -1); // 10个元素, 每个元素都被初始化为-1;
  vector<string> svec(10, "hi!"); //10个元素, 每个元素都被初始化为"hi!"

  vector<int> v1(10); // 10 elements with value 0;
  vector<int> v2{10}; // 1 element with value 10;
  vector<int> v3(10, 1); // 10 elements with value 1;
  vector<int> v4{10, 1}; // 2 elements with value 10 and 1

  vector<string> v5{"hi"}; // list initalization: v5 has 1 elements with value "hi";
  //vector<string> v6("hi");
  vector<string> v7{10};
  vector<string> v7_1(10);
  vector<string> v8{10, "a"};
  ShowVectorElement(v7);
  ShowVectorElement(v7_1);
  ShowVectorElement(v8);

  return 0;
}
