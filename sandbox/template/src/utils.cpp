#include "utils.hpp"

RMQ::RMQ(const std::vector<int>& input_vector)
{
    size_t pow = std::ceil(std::log2(input_vector.size()));
    size_t pow_len = std::pow(2,  pow);
    minimum_table.push_back(input_vector);
    minimum_table[0].resize(pow_len, __INT_MAX__);
    int current_pow = pow - 1;
    int curr_pow = 1;
    for(int i = 1; i < pow + 1; ++i)
    {
        minimum_table.push_back(std::vector<int>());
        for(int j = 0; j < minimum_table[i - 1].size() - curr_pow; ++j)
        {
            minimum_table[i].push_back(std::min(minimum_table[i - 1][j], minimum_table[i - 1][j + curr_pow]));
        }
        curr_pow *= 2;
    }
}

int RMQ::findMin(const unsigned int left, const unsigned int right){
    size_t row = std::floor(std::log2(right - left + 1));
    return std::min(minimum_table[row][left], minimum_table[row][right - std::pow(2, row) + 1]);
}
