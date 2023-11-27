#include "Jonson.hpp"
#include <iostream>


int main() { 
    std::vector<std::vector<std::pair<int, int>>> graph{{{5, 1}}, {{0, 1}}, {{1, 1}, {3, 1}}, {{4, 1}}, {{5, 1}}, {{2, 3}}};
    std::vector<std::vector<int>> d = jonson(graph);
    for(int i = 0; i < d.size(); ++i){
        for(int j = 0; j < d.size(); ++j)
            std::cout << d[i][j] << " ";
        std::cout << '\n';
    }
}
