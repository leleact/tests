#include <iostream>
#include <thread>

int thread_function(int &i) {
    return 0;
}
int main(int argc, char *argv[]) {
    std::thread    threads[10];
    for (int i = 0; i < 10; i++) {
        threads[i] = std::thread(thread_function, std::ref(i)); 
    }

    for( auto &th : threads) {
        th.join(); 
    }
    return 0;
}
