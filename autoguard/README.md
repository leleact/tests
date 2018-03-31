``` cpp
#include <iostream>
#include <string>
#include <map>
#include <pthread.h>

template<typename T, int (T::*lock)(), int (T::*unlock)()>
class AutoGuard {
public:
    AutoGuard(T &t) : m_value(t) {
        (m_value.*lock)(); 
    }

    ~AutoGuard() {
        (m_value.*unlock)(); 
    }
private:
    /**
     * T m_value时会出发T的 T(const T &)的拷贝构造函数
     * T &m_value不会
     * const T &m_value 要求int (T::*lock)()和int (T::*unlock)() const
     * 要求T中 lock和unlock函数为const
     */
    T& m_value;
};

class CReadWriteLock {
public:
    CReadWriteLock() {
        std::cout << "CReadWriteLock::CReadWriteLock()" << std::endl;
        pthread_rwlock_init(&m_mutex, NULL);
    }
    ~CReadWriteLock() {
        pthread_rwlock_destroy(&m_mutex);
    }

    int ReadAcquire() {
        std::cout << "CReadWriteLock::ReadAcquire()"  << std::endl;
        return pthread_rwlock_rdlock(&m_mutex);
    }

    int ReadRelease() {
        std::cout << "CReadWriteLock::ReadRelease()"  << std::endl; 
        return pthread_rwlock_unlock(&m_mutex);
    }

    int WriteAcquire() {
        std::cout << "CReadWriteLock::WriteAcquire()"  << std::endl; 
        return pthread_rwlock_wrlock(&m_mutex);
    }

    int WriteRelease() {
        std::cout << "CReadWriteLock::WriteRelease()"  << std::endl;  
        return pthread_rwlock_unlock(&m_mutex);
    }
private:
    CReadWriteLock(const CReadWriteLock &) {
        std::cout << "CReadWriteLock::CReadWriteLock(const &)"  << std::endl;  
    }
    CReadWriteLock &operator=(const CReadWriteLock &) {
        std::cout << "CReadWriteLock::operator=(const &)"  << std::endl;  
        return *this; 
    }

    pthread_rwlock_t m_mutex;
};

typedef AutoGuard< CReadWriteLock, &CReadWriteLock::ReadAcquire, &CReadWriteLock::ReadRelease > AutoReadLock;
typedef AutoGuard< CReadWriteLock, &CReadWriteLock::WriteAcquire, &CReadWriteLock::WriteRelease > AutoWriteLock;
typedef struct st_Data {
    int m_count;
    CReadWriteLock rwLock;
    std::map<long, int> m_Map;
} stData;

void *pfun(void *arg) {
    stData *pstData = (stData *)arg;   
    while(1) {
        AutoWriteLock l(pstData->rwLock);
        if (pstData->m_count <= 0)
            break;
        long thread_id = pthread_self();
        std::cout << "thread_id:" << thread_id << ", count:" << pstData->m_count-- << std::endl;
        if (pstData->m_Map.find(thread_id) == pstData->m_Map.end())
            pstData->m_Map.insert(std::pair<long, int>(thread_id, 0));

        pstData->m_Map[thread_id]++;
    }
    return (void *)0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "use "  << argv[0] << " [COUNT] [THREAD_NUM]" << std::endl;
        return -1;
    }
    stData data;
    data.m_count = std::atoi(argv[1]);
    int thread_num = std::atoi(argv[2]);
    pthread_t arr[thread_num];
    for(int i = 0; i < thread_num; i++) {
        pthread_create(&arr[i], NULL, pfun, (void *)&data);
    }

    void *thread_ret;
    for(int i = 0; i < thread_num; i++) {
        pthread_join(arr[i], &thread_ret);
    }

    int iTotal = 0;
    for(std::map<long, int>::iterator iter = data.m_Map.begin(); iter != data.m_Map.end(); iter++) {
        std::cout << "thread_id:"  << iter->first << ", count:" << iter->second << std::endl;
        iTotal += iter->second;
    }
    std::cout << "Total:" << iTotal << std::endl;
    return 0;
}
```
