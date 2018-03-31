#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <iomanip>

int main(int argc, char *argv[]) {
    if ( argc < 2) {
        std::cout << "Arg Error" << std::endl;
        return -1;
    }

    std::string file_name = argv[1];

    std::cout << "====================" << std::endl;
    long index = 1;
    std::ofstream out( file_name.c_str(), std::iostream::app|std::iostream::out);
    while( true ) {
        if ( index > 1800 )
            break;
        std::ostringstream os;
        os << std::setw(4) << index++;
        out << os.str()  << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds(1) );
        std::cout << "good bit[" << out.good() << "]" << "bad bit[" << out.bad() << "]"
            << "fail bit[" << out.fail() << "]" << "stat[" << out.rdstate() << "]" << std::endl;
    }
    out.close();
    std::cout << "====================" << std::endl << std::endl;
    return 0;
}
