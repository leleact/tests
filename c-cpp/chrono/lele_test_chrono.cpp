#include <iostream>
#include <chrono>
int main ()
{
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

    auto value = now_ms.time_since_epoch();
    long duration = value.count();

    std::chrono::milliseconds dur(duration);

    std::chrono::time_point<std::chrono::system_clock> dt(dur);

    if (dt != now_ms)
        std::cout << "Failure." << std::endl;
    else
        std::cout << "Success." << std::endl;
}
