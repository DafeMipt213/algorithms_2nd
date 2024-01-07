#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

map<string, string> params;
long long get(string name, long long def = 0) {
    if (params.count(name)) {
        return stoll(params[name]);
    } else {
        return def;
    }
}

string spam(const string& s, size_t len) {
    string res;
    while (res.size() < len) res += s;
    res.resize(len);
    return res;
}

bool check_state(const array<int, 10>& cnt) {
    const int last = cnt[9];
    vector<char> used(3);

    int a = last == 0 ? 1 : 0;
    int b = last == 2 ? 1 : 2;

    used[last] = true;
    for (int iter = 2; iter--; swap(a, b)) {
        if (cnt[3*a + last]) {
            used[a] = 1;
            if (cnt[3*b + a] || cnt[3*b + last]) {
                used[b] = true;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (!used[i] && (cnt[3*i+0] || cnt[3*i+1] || cnt[3*i+2])) return false;
    }
    return true;
}

bool operator < (const array<int, 10>& lhs, const array<int, 10>& rhs) {
    for (size_t i = 0; i < 10; ++i) {
        if (lhs[i] != rhs[i]) {
            return lhs[i] < rhs[i];
        }
    }
    return false;
}

vector<string> gen_brute(const int n, const int a, const int sum_n, const int max_q, const int min_a) {
    map<array<int, 10>, int> dp;
    vector<array<int, 10>> states;
    vector<array<int, 10>> res;

    array<int, 10> empty_array;
    fill(empty_array.begin(), empty_array.end(), 0);
    empty_array[9] = 0; dp[empty_array] = 1; states.push_back(empty_array);
    empty_array[9] = 1; dp[empty_array] = 1; states.push_back(empty_array);
    empty_array[9] = 2; dp[empty_array] = 1; states.push_back(empty_array);
    empty_array[9] = 4; dp[empty_array] = 3;

    int sum = 0;
    for (int i = 0; i != (int)states.size(); ++i) {
        array<int, 10> cur = states[i];
        const int last = cur[9];

        int len = 1;
        for (int i = 0; i < 9; ++i) len += cur[i];
        if (len == n) continue;

        if (sum + len > sum_n) break;
        if (res.size() == max_q) break;

        const int count = dp[cur];
        bool ok = count <= a;

        if (i >= 3) {
            for (int j = 0; j < 3; ++j) {
                if (!cur[3*j + last]) continue;

                cur[3*j+last]--;
                cur[9] = j;
                if (!dp.count(cur) && check_state(cur)) {
                    ok = false;
                }
                cur[3*j+last]++;
                cur[9] = last;
            }
        }

        if (!ok) {
            dp.erase(cur);
            continue;
        }

        cur[9] = 4;
        if (min_a <= dp[cur] && dp[cur] <= a) {
            cur[9] = last;
            sum += len;
            res.push_back(cur);
        } else {
            cur[9] = last;
        }

        for (int j = 0; j < 3; ++j) {
            cur[3*last + j]++;
            cur[9] = j;
            if (!dp.count(cur)) states.push_back(cur);
            dp[cur] += count;

            cur[9] = 4;
            dp[cur] += count;

            cur[9] = last;
            cur[3*last + j]--;
        }
    }

    vector<string> test;
    for (auto cur : res) {
        string res;
        res.push_back(cur[9] + 'a');

        while (true) {
            const int last = cur[9];

            int next = -1;
            for (int j = 0; j < 3; ++j) {
                if (!cur[3*j + last]) continue;

                cur[3*j+last]--;
                cur[9] = j;
                if (check_state(cur)) next = j;
                cur[3*j+last]++;
                cur[9] = last;
            }

            if (next == -1) break;
            cur[3*next+last]--;
            cur[9] = next;
            res.push_back(next + 'a');
        }

        test.push_back(res);
    }

    return test;
}

vector<string> generate() {
    string type = params["type"];

    if (type == "full") {
        const size_t n = get("n");
        return vector<string>{ spam("aabbccacb", n) };
    } else if (type == "quick") {
        const size_t n = get("n");
        return vector<string>{ spam("abcacb", n) };
    } else if (type == "brute") {
        const size_t n = get("n");
        const size_t a = get("a");
        const size_t min_a = get("min");
        const size_t sum_n = get("s");
        const size_t max_q = get("q");
        return gen_brute(n, a, sum_n, max_q, min_a);
    }
    return vector<string>();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 1; i < argc; i++) {
        string s = string(argv[i]);
        if (s.find("=") != string::npos) {
            auto pos = s.find("=");
            params[s.substr(0, pos)] = s.substr(pos + 1);
        } else {
            params[s] = "";
        }
    }

    const size_t group = get("g");
    const auto test = generate();

    cout << group << '\n';
    cout << test.size() << '\n';
    for (const string& w : test) {
        cout << w << '\n';
    }
}