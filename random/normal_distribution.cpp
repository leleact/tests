#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>

int main(int argc, char *argv[]) {
    /**
     * 1. argv[1] 产生随机数个数
     * 2. argv[2] 平均值
     * 3. argv[3] 方差
     * 4. argv[4] 最高值
     */
    std::size_t arg1 = std::atol( argv[1] );
    std::size_t arg2 = std::atol( argv[2] );
    std::size_t arg3 = std::atol( argv[3] );
    std::size_t arg4 = std::atol( argv[4] );

    std::time_t result = std::time(nullptr);
	std::default_random_engine e(result); //引擎
	std::normal_distribution<> n(arg2, arg3); //均值, 方差
    std::vector<long> vc(15);
    for(std::size_t i = 0; i < arg1;) {
        long val = std::lround(n(e));
        if (val < 0 || val >= (long)arg4)
            continue;
        else
            i++;
        int index = int(val / 50);
        vc[index]++;
	}
    for (std::size_t j = 0; j < 15; j++) {
        std::cout << std::setw(3) << j * 50 << "-" << std::setw(3) << (j+1) * 50 
            << ":" << std::setw(10) << vc[j] << "|" << std::string(vc[j] * 100 / arg1, '*') << std::endl;
    }
	return 0;
}
