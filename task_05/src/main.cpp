#include <iostream>
#include <vector>
#include <cmath>
#include "RMQ.hpp"



int main () {
    int n; 
    std::cin >> n;

    std::vector<int> vec;

    int tmp;

    for( int i = 0; i < n; ++i ) {
        std::cin >> tmp;
        vec.push_back(tmp);
    }
        
    std::vector< std::vector<int> > vec2D = table_construct(n, vec);

    int a, b;
    std::cin >> a >> b;

    int k = RMQ(a, b, vec2D);
}