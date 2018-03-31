#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <pthread.h>

int nBerun = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_show;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_show;

int g_nSource = 100000;
int eventOK = 0;

void *ThreadDealMessage(void *pArg) {
  while(nBerun) {
    pthread_mutex_lock(&mutex);
    /**
     * 如果wait唤醒之后eventOK又马上不OK了, 那么需要循环去判断eventOK是否OK
     * 第一次初始化时需要唤醒一下
     */
    if (eventOK == 0)
      pthread_cond_wait(&cond, &mutex); // 如果wait唤醒之后eventOK又马上变为0
    eventOK = 0;
    pthread_mutex_unlock(&mutex);

    g_nSource--; /* do what you want */
    std::cout << "do..." << std::endl;
  }
  return (void *)pArg;
}

void *ThreadGetMessage(void *pArg) {
  while(1) {
    pthread_mutex_lock(&mutex);
    if (g_nSource++ > 10000)
      eventOK = 1;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
  }

  return (void *)pArg;
}

int main() {
  int nRet = 0;
  const int nThreadNum = 10;
  pthread_t pidThreadDealMess[nThreadNum], pidGetMess;

  pthread_mutex_init(&mutex_show, NULL);
//  std::cout << mutex_show << std::endl;

  for (int i = 0; i < nThreadNum; i++) {
    nRet = pthread_create(&pidThreadDealMess[i], NULL, ThreadDealMessage, NULL);
    if (nRet) {
      std::cout << "pthread_create error" << std::endl;
      exit(1);
    }
  }

  nRet = pthread_create(&pidGetMess, NULL, ThreadDealMessage, NULL);
  if (nRet) {
    std::cout << "pthread_create error" << std::endl;
    exit(1);
  }

  eventOK = 1;
  pthread_cond_signal(&cond);

  for (int i = 0; i < nThreadNum; i++) {
    pthread_join(pidThreadDealMess[i], NULL);
  }
  pthread_join(pidGetMess, NULL);

  return 0;
}
