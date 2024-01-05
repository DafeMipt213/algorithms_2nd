#include <vector>

class RMQ
{
    private:
        std::vector<std::vector<int>> data_;
    public:
        RMQ(std::vector<int> input) : data_(std::__lg(input.size() + 1), std::vector<int>(input.size()))
        {
            const size_t n = input.size();
            std::copy(input.begin(), input.end(), data_[0].begin());

            for (int l = 0; l < std::__lg(n); l++)
                for (int i = 0; i + (2 << l) <= n; i++)
                    data_[l+1][i] = std::min(data_[l][i], data_[l][i + (1 << l)]);
        }

        int rmq(const size_t l, const size_t r) const
        {
            const size_t power_2 = std::__lg(r - l);
            return std::min(data_[power_2][l], data_[power_2][r - (1 << power_2) + 1]);
        }
};
