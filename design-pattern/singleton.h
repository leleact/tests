#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#ifndef _SINGLETON_H
#define _SINGLETON_H
class Singleton {
private:
  Singleton();
  static Singleton *m_pinstance;
public:
  static std::shared_ptr<Singleton> Getinstance(); 
  static std::mutex m_Mutex;
};
#endif
