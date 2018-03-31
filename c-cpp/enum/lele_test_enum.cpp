#include <iostream>

namespace {

    enum ERR_CODE
    {
        START,
        END
    };

    void fun1(ERR_CODE &errcode)
    {
        std::cout << errcode << std::endl;
    }

    int main() {
        ERR_CODE a;
        a = END;
        std::cout << a << std::endl;

        fun1(a);
        return 0;
    }

}


namespace test {

    enum class Error {
        error1 = 1,
        error2,
        error3,
        error4
    };

    int main(int argc, char *argv[]) {
        Error e = Error::error2;
        std::cout << static_cast<int>(e) << std::endl;
        return 0;
    }

}

int main(int argc, char *argv[]) {
    return test::main(argc, argv);
}
