#define BOOST_LOG_DYN_LINK
#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include "boost/log/trivial.hpp"

class Item
{
    friend std::ostream& operator<<(std::ostream& os, const Item& it)
    {
        os << it.m_;
        return os;
    }
public:
    Item(const std::string& s):m_(s) {BOOST_LOG_TRIVIAL(trace) << "===========> Item constructor <==========";}
private:
    std::string m_;
};

int main()
{
    BOOST_LOG_TRIVIAL(trace)  << "=========================== start ==========================";

    Item it("xs");
    BOOST_LOG_TRIVIAL(trace) << it;

    BOOST_LOG_TRIVIAL(trace)  << "=========================== end ==========================";
    return 0;
}

// g++ -std=c++11 Main.cpp -I$HOME/.local/include -L$HOME/.local/lib -lboost_log -pthread
