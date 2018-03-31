#include <iostream>
#include <vector>
int main(void) {
    std::vector<int> vc = {1 , 4, 11, 7, 9, 6, 4, 2, 10, 9 , 9 ,9 };

    int index_top = 0;
    int max_num = 0;
    for (std::size_t index = 0; index < vc.size(); index++) {
        if ( max_num < vc[index]) {
            max_num = vc[index];
            index_top = index;
        }
    }
    std::cout << "MAX NUM IS:" << max_num << ", MAX INDEX IS:" << index_top << std::endl;

    for (int i = max_num; i > 0; i--) {
        for(int j = 0; j < static_cast<long>(vc.size()); j++) {
            if ( vc[j] >= i)
                std::cout << "     ■     ";
            else
                std::cout << "            ";
        }
        std::cout << std::endl;
    }
    return 0;
}
