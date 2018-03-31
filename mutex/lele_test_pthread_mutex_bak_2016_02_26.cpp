#include <iostream>
#include <pthread.h>

// 堆栈中多次调用同一个锁也会死锁

typedef struct st_Data {
    int M_data;
    pthread_mutex_t M_mutex;
} stData;

void fun();

stData data;
int main(int argc, char *argv[]) {
    data.M_data = 0;
    pthread_mutex_init(&data.M_mutex, NULL);

    pthread_mutex_lock(&data.M_mutex);
    data.M_data += 1;
    fun();

    pthread_mutex_unlock(&data.M_mutex);

    std::cout << data.M_data << std::endl;
    return 0;
}

void fun() {
    pthread_mutex_lock(&data.M_mutex);
    data.M_data += 1;
    pthread_mutex_unlock(&data.M_mutex);
}
