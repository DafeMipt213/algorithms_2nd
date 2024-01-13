#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>


class RMQ {
public:
    std::pair<size_t, size_t> ans;
	std::pair<size_t, size_t> findRMQ(std::vector<size_t>& data, size_t l, size_t r);
	RMQ(std::vector<size_t>& data, size_t l, size_t r) {ans = findRMQ(data, l, r);}
};