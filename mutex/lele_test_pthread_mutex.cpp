/**
 * 即使mutex1和mutex2值相等，他们也是不同的互斥量
 */
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <pthread.h>

struct SSource {
  int nSource;
};

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

struct SSource g_stSource1;
struct SSource g_stSource2;

void *func1(void *arg) {
  int nRet = 0; 
  nRet = pthread_mutex_lock(&mutex1);
  if (nRet) {
    std::cerr << "pthread_mutex_lock error" << std::endl;
    exit(1);
  }

  // 请求同一个锁两次会一直锁下去
  // func1即使退出，对mutex的锁也不会自动解锁
  std::cout << "lock twice begin" << std::endl;
  nRet = pthread_mutex_lock(&mutex2);
  if (nRet) {
    std::cerr << "pthread_mutex_lock error" << std::endl;
    exit(1);
  }
  std::cout << "lock twice end" << std::endl;

  std::cout << "Thread: " << pthread_self() << " g_stSource1 get locked" << std::endl;
  
  sleep(10);

  nRet = pthread_mutex_unlock(&mutex1);
  if (nRet) {
    std::cerr << "pthread_mutex_unlock error"  << std::endl;
  }

  std::cout << "Thread: " << pthread_self() << " g_stSource1 unlocked and finished" << std::endl;

  return (void *)(1);
}

void *func2(void *arg) {
  int nRet = 0; 
  nRet = pthread_mutex_lock(&mutex2);
  if (nRet) {
    std::cerr << "pthread_mutex_lock error" << std::endl;
    exit(1);
  }
  std::cout << "Thread: " << pthread_self() << " g_stSource2 get locked" << std::endl;

  nRet = pthread_mutex_unlock(&mutex2);
  if (nRet) {
    std::cerr << "pthread_mutex_unlock error"  << std::endl;
  }

  std::cout << "Thread: " << pthread_self() << " g_stSource2 unlocked and finished" << std::endl;

  return (void *)(2);
}

int main() {
  mutex1 = PTHREAD_MUTEX_INITIALIZER;
  g_stSource1.nSource = 10;

  mutex2 = PTHREAD_MUTEX_INITIALIZER;
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

  std::cout << "g_stSource1.nSource = [" << g_stSource1.nSource << "], "
    << "g_stSource2.nSource = [" << g_stSource2.nSource << "]" << std::endl;

  return 0;
}
