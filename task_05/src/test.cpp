#include <gtest/gtest.h>
#include "rmq.hpp"

TEST(RMQ, Simple) {
    std::vector<int> arr = {4, 2, 7, 1, 3, 6, 9, 5};
    SparseTable sparseTable(arr);

    ASSERT_EQ(sparseTable.query(1, 5), 3);
    ASSERT_EQ(sparseTable.query(2, 7), 1);
}

TEST(RMQ, Complex) {
    std::vector<int> arr = {4, 2, 7, 1, 3, 6, 9, 5};
    SparseTable sparseTable(arr);

    ASSERT_EQ(sparseTable.query(1, 5), 3);
    ASSERT_EQ(sparseTable.query(2, 7), 1);
    ASSERT_EQ(sparseTable.query(3, 6), 4);
}

TEST(RMQ, AnotherComplex) {
    std::vector<int> arr = {5, 8, 3, 1, 6, 2, 7, 4};
    SparseTable sparseTable(arr);

    ASSERT_EQ(sparseTable.query(0, 7), 3);
    ASSERT_EQ(sparseTable.query(2, 5), 2);
    ASSERT_EQ(sparseTable.query(1, 3), 3);
}

TEST(RMQ, EdgeCases) {
    std::vector<int> arr = {1};
    SparseTable sparseTable(arr);

    ASSERT_EQ(sparseTable.query(0, 0), 0);

    std::vector<int> emptyArr;
    SparseTable emptySparseTable(emptyArr);

    ASSERT_EQ(emptySparseTable.query(0, 0), -1);  // Assuming -1 as a sentinel value for an empty array.
}
