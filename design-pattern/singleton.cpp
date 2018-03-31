#include "singleton.h"
Singleton *Singleton::m_pinstance = nullptr;

std::shared_ptr<Singleton> Singleton::Getinstance() {
  if (m_pinstance == nullptr) {
    m_Mutex.lock(); 
    if (m_pinstance == nullptr) {
      m_pinstance = new Singleton();
    }
    m_Mutex.unlock();
  }
  return std::make_shared<Singleton>(m_pinstance);
}
