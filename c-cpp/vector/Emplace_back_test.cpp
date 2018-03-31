#include <iostream>
#include <vector>
#include <string>

#define _PF std::clog << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__ << "]" << std::endl;

class Item {
    std::string M_sk;
    int M_il;
public:
    Item(const std::string& str, const int& i):M_sk(str),M_il(i) { _PF }
    Item(const Item& item) : M_sk(item.M_sk), M_il(item.M_il) { _PF }
    Item(Item&& item) : M_sk(std::move(item.M_sk)), M_il(std::move(item.M_il)) { _PF }
    Item& operator=(const Item& item) {
        this->M_sk = item.M_sk;
        this->M_il = item.M_il;
        _PF
        return *this;
    }
    Item& operator=(Item&& item) {
        this->M_sk = std::move(item.M_sk);
        this->M_il = std::move(item.M_il);
        _PF
        return *this;
    }
    ~Item() { _PF }
};

int main(int argc, char *argv[]) {
    {
        std::vector<Item> vec;
        vec.emplace_back("aaa", 1);
    }

    {
        std::vector<Item> vec;
        Item it("bbb", 10);
        vec.emplace_back(it);
    }
}
