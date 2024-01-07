#include "testlib.h"

#include <string>

char was[3];
char graph[3][3];

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    const size_t g = opt<int>(1);
    const size_t n = opt<int>(2);
    const size_t q = opt<int>(3);
    const auto pattern = opt<std::string>(4);

    for (char c : pattern) was[c - 'a'] = true;
    for (size_t i = 0; i + 1 < pattern.size(); ++i) {
        graph[pattern[i] - 'a'][pattern[i+1] - 'a'] = true;
    }

    std::vector<char> start;
    for (size_t i = 0; i < 3; ++i) if (was[i]) start.push_back('a' + i);
    std::vector<std::vector<char>> go(3);
    for (size_t i = 0; i + 1 < pattern.size(); ++i) {
        go[pattern[i] - 'a'].push_back(pattern[i+1]);
    }

    std::cout << g << std::endl << q << std::endl;
    for (size_t testcase = 1; testcase <= q; ++testcase) {
        std::string s{rnd.any(start)};
        while (s.size() < n) {
            if (go[s.back() - 'a'].empty()) {
                break;
            } else {
                s.push_back(rnd.any(go[s.back() - 'a']));
            }
        }

        std::cout << s << std::endl;
    }
}
