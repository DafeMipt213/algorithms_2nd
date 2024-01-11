#ifndef RMQ_HPP
#define RMQ_HPP

#include <vector>
#include <cmath>

class SparseTable {
public:
    SparseTable(const std::vector<int>& array);
    int query(int left, int right);

private:
    std::vector<int> array;
    int n, k;
    std::vector<std::vector<int>> table;
    void buildTable();
};

#endif
