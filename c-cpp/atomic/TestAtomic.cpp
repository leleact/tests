#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>

namespace varlib {
namespace test {

class Counter {
public:
    Counter() {}
    Counter(int x) : m_counter(x) {}
    void Increse() { m_counter++;}
    void Decrease() { m_counter--; }
    int getCounter() { return m_counter.load(); }

private:
    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;
private:
    std::atomic<int> m_counter;
};

void func1(Counter *c) {
    std::clog << "step into thread id [" << std::this_thread::get_id() << "] count [" << c->getCounter() << "]" << std::endl;;
    //@ERROR NOT ATOMIC
    while( c->getCounter() > 0 ) {
        c->Decrease();
    }
    std::clog << "step out thread id [" << std::this_thread::get_id() << "] count [" << c->getCounter() << "]" << std::endl;;
}

}}

using namespace varlib::test;

int main(int argc, char *argv[]) {
    if ( argc != 2 ) {
        std::cerr << "Args missing!" << std::endl;
        return -1;
    }

    Counter c(atol(argv[1]));

    std::thread t1(func1, &c);
    std::thread t2(func1, &c);

    t1.join();
    t2.join();

    std::clog << "ThreadID:" << std::this_thread::get_id() << " " << c.getCounter() << std::endl;
}
