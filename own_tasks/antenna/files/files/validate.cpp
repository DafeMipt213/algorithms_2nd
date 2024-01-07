// Created by Nikolay Budin

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

int MAXN = 100000;
int MAXM = 100000;
int MAXS = 1'000'000'000;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	if (validator.group() == "1") {
		MAXN = 8;
		MAXS = 100;
	} else if (validator.group() == "2") {
		MAXN = 8;
		MAXS = 100;
	} else if (validator.group() == "3") {
		MAXN = 1000;
	} else if (validator.group() == "5") {
		MAXS = 100;
	}

	int n = inf.readInt(1, MAXN, "n");
	inf.readEoln();

	ll summ = 0;
	for (int i = 0; i < n; ++i) {
		int m = inf.readInt(1, MAXM, format("m_%d", i + 1));

		if (validator.group() == "1") {
			ensuref(m == 1, "m_%d should be 1 (group #1)", i + 1);
		}

		inf.readSpace();
		summ += m;
		int s = inf.readInt(0, MAXS, format("s_%d", i + 1));
		inf.readEoln();
		int from = 0;
		for (int j = 0; j < m; ++j) {
			int pos = inf.readInt(from, s, format("p_{%d, %d}", i + 1, j + 1));
			from = pos + 1;
			if (j < m - 1) {
				inf.readSpace();
			}
		}

		inf.readEoln();
	}

	ensuref(summ <= MAXM, "too many bookmarks");

	inf.readEof();

	if (validator.group() == "4") {
		ensuref(summ > n, "sum m_i > n (group #4)");
	}

	return 0;
}