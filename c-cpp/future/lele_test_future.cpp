#include <iostream>
#include <future>
#include <thread>
#include <chrono>

namespace varlib {
    static long getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        auto value = now_ms.time_since_epoch();
        long duration = value.count();
        return duration;
    }
}

namespace v1 {

int main() {
    //future from a packaged_task
    std::packaged_task<int()> task([](){
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__
            << "]{tid:" << std::this_thread::get_id() << ", time:" << varlib::getCurrentTime() << "}" << std::endl;
            return 7;
            }); // wrap the function
    std::future<int> f1 = task.get_future();  // get a future
    std::thread(std::move(task)).detach(); // launch on a thread

    // future from an async()
    std::future<int> f2 = std::async(std::launch::async, [](){
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__
            << "]{tid:" << std::this_thread::get_id() << ", time:" << varlib::getCurrentTime() << "}" << std::endl;
            return 8;
            });

    // future from a promise
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread( [&p]{
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__
            << "]{tid:" << std::this_thread::get_id() << ", time:" << varlib::getCurrentTime() << "}" << std::endl;
            p.set_value_at_thread_exit(9);
            }).detach();

    std::cout << "Waiting..." << std::flush;
    std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__
        << "]{tid:" << std::this_thread::get_id() << ", time:" << varlib::getCurrentTime() << "}" << std::endl;
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done!\nResults are: "
        << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
    return 0;
}
}

namespace v20171228 {
    int main(int argc, char *argv[]) {
        std::promise<std::string> promise;
        std::future<std::string> future = promise.get_future();
        std::thread([&promise]{
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__
            << "]{tid:" << std::this_thread::get_id() << ", time:" << varlib::getCurrentTime() << "}" << std::endl;
            promise.set_value_at_thread_exit("hello world");
                }).detach();

        std::cout << "Done!\n result: [" << future.get() << "]" << std::endl;;
        return 0;
    }
}

int main(int argc, char *argv[]) {
    return v20171228::main(argc, argv);
}
