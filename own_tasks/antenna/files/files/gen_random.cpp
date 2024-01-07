// Generator created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "testlib.h"
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;

vector<int> gen_comb(int n, int k) {
	assert(0 <= k && k <= n);
	if (k < n / 2) {
		set<int> chosen;
		while (szof(chosen) < k) {
			chosen.insert(rnd.next(n));
		}
		return vector<int>(chosen.begin(), chosen.end());
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	shuffle(order.begin(), order.end());
	order.resize(k);
	sort(order.begin(), order.end());
	return order;
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n = opt<int>("n");
	int summ = opt<int>("summ");
	assert(n <= summ);
	int maxs = 1000000000;
	if (__testlib_opts.count("maxs")) {
		maxs = opt<int>("maxs");
	}

	vector<int> arrm(n, 1);
	for (int i = n; i < summ; ++i) {
		int pos = rnd.next(n);
		if (arrm[pos] == maxs + 1) {
			--i;
			continue;
		}
		arrm[pos]++;
	}

	cout << n << "\n";

	for (int i = 0; i < n; ++i) {
		int m = arrm[i];
		int s = rnd.next(m - 1, maxs);
		cout << m << " " << s << "\n";
		vector<int> pos = gen_comb(s + 1, m);
		for (int j = 0; j < m; ++j) {
			cout << pos[j];
			if (j < m - 1) {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}