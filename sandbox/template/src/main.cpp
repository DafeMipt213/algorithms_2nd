#include <iostream>
#include "utils.hpp"


int main() {
    
    std::vector<int> pasha{1, 10, 7, 6, 3, 2, 1, 11};
    RMQ pashka(pasha);
    std::cout << pashka.findMin(3, 4) << '\n';
    return 0; 
}
