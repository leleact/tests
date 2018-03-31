#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <map>
#include <vector>

using FuncType = int (int, char *[]);

static std::vector<std::function<FuncType>> functions;

namespace v20170720 {
    std::once_flag flag1, flag2;

    void fun() {
        std::cout << "[" << std::this_thread::get_id() << "](" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__ << "]"  << std::endl;
    }

    void muiltiThreadFunc() {
        std::call_once(flag2, fun);
    }

    int main(int argc, char *argv[]) {
        std::cout << "\n\n\n==============================" << std::endl;
        int i = 0;
        while( i++ < 100) {
            std::call_once(flag1, fun);
        }
        std::cout << "==============================\n\n\n" << std::endl;
        return 0;
    }

    int main_multiThread(int argc, char *argv[]) {
        std::cout << "\n\n\n==============================" << std::endl;

        std::thread t1(muiltiThreadFunc);
        std::thread t2(muiltiThreadFunc);
        std::thread t3(muiltiThreadFunc);

        t1.join();
        t2.join();
        t3.join();

        std::cout << "==============================\n\n\n" << std::endl;
        return 0;
    }
}

int main(int argc, char *argv[]) {
    functions.push_back( v20170720::main );
    functions.push_back( v20170720::main_multiThread );

    for(auto v : functions) {
        v(argc, argv);
    }
}
