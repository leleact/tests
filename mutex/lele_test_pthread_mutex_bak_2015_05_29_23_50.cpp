#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <pthread.h>

struct SSource {
  pthread_mutex_t mutex;
  int nSource;
};

struct SSource g_stSource1;
struct SSource g_stSource2;

void *func1(void *arg) {
  int nRet = 0; 
  nRet = pthread_mutex_lock(&g_stSource1.mutex);
  if (nRet) {
    std::cerr << "pthread_mutex_lock error" << std::endl;
    exit(1);
  }

  /* 请求同一个锁两次会一直锁下去
  std::cout << "lock twice begin" << std::endl;
  nRet = pthread_mutex_lock(&g_stSource1.mutex);
  if (nRet) {
    std::cerr << "pthread_mutex_lock error" << std::endl;
    exit(1);
  }
  std::cout << "lock twice end" << std::endl;
  */

  std::cout << "Thread: " << pthread_self() << " g_stSource1 get locked" << std::endl;
  
  sleep(10);

  nRet = pthread_mutex_unlock(&g_stSource1.mutex);
  if (nRet) {
    std::cerr << "pthread_mutex_unlock error"  << std::endl;
  }

  std::cout << "Thread: " << pthread_self() << " g_stSource1 unlocked and finished" << std::endl;

  return (void *)(1);
}

void *func2(void *arg) {
  int nRet = 0; 
  nRet = pthread_mutex_lock(&g_stSource2.mutex);
  if (nRet) {
    std::cerr << "pthread_mutex_lock error" << std::endl;
    exit(1);
  }
  std::cout << "Thread: " << pthread_self() << " g_stSource2 get locked" << std::endl;

  nRet = pthread_mutex_unlock(&g_stSource2.mutex);
  if (nRet) {
    std::cerr << "pthread_mutex_unlock error"  << std::endl;
  }

  std::cout << "Thread: " << pthread_self() << " g_stSource2 unlocked and finished" << std::endl;

  return (void *)(2);
}

int main() {
  g_stSource1.mutex = PTHREAD_MUTEX_INITIALIZER;
  g_stSource1.nSource = 10;

  g_stSource2.mutex = PTHREAD_MUTEX_INITIALIZER;
  g_stSource2.nSource = 100;

  pthread_t pid1;
  pthread_t pid2;
  int nRet = 0;
  nRet = pthread_create(&pid1, NULL, func1, NULL);
  if (nRet) {
    std::cerr << "pthread_create error" << std::endl;
    exit(1);
  }
  sleep(3);
  nRet = pthread_create(&pid2, NULL, func2, NULL);
  if (nRet) {
    std::cerr << "pthread_create error" << std::endl;
    exit(1);
  }

  void *vpRet;

  nRet = pthread_join(pid1, &vpRet);
  if (nRet) {
    std::cerr << "pthread_join error" << std::endl;
    exit(1);
  }

  nRet = pthread_join(pid2, &vpRet);
  if (nRet) {
    std::cerr << "pthread_join error" << std::endl;
    exit(1);
  }

  return 0;
}
