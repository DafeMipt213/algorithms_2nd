#include "rmq.hpp"


SparseTable::SparseTable(const std::vector<int>& array) {
    this->array = array;
    this->n = array.size();
    this->k = std::log2(n) + 1;
    buildTable();
}

int SparseTable::query(int left, int right) {
    int j = std::log2(right - left + 1);
    if (array[table[left][j]] <= array[table[right - (1 << j) + 1][j]]) {
        return table[left][j];
    } else {
        return table[right - (1 << j) + 1][j];
    }
}

void SparseTable::buildTable() {
    table.resize(n, std::vector<int>(k));

    for (int i = 0; i < n; ++i) {
        table[i][0] = i;
    }

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            if (array[table[i][j - 1]] <= array[table[i + (1 << (j - 1))][j - 1]]) {
                table[i][j] = table[i][j - 1];
            } else {
                table[i][j] = table[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}
