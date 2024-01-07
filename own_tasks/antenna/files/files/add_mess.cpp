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

int rnd_ineq(int l, int r, int val) {
	while (true) {
		int ret = rnd.next(l, r);
		if (ret != val) {
			return ret;
		}
	}
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n;
	cin >> n;
	vector<pair<int, vector<int>>> books;

	for (int i = 0; i < n; ++i) {
		int m, s;
		cin >> m >> s;
		books.push_back({s, {}});
		for (int j = 0; j < m; ++j) {
			int pos;
			cin >> pos;
			books[i].ss.push_back(pos);
		}
	}

	string type = opt<string>("type");

	while (true) {
		int ind = rnd.next(n);
		auto& [s, arrpos] = books[ind];
		if (szof(arrpos) + 1 == s) {
			continue;
		}
		if (szof(arrpos) == 1) {
			arrpos[0] = rnd.next(s + 1);
			break;
		}
		if (type == "first") {
			if (arrpos[1] > 1) {
				arrpos[0] = rnd_ineq(0, arrpos[1] - 1, arrpos[0]);
				break;
			}
		}

		if (type == "last") {
			if (arrpos[szof(arrpos) - 2] < s - 1) {
				arrpos.back() = rnd_ineq(arrpos[szof(arrpos) - 2] + 1, s, arrpos.back());
				break;
			}
		}

		if (type == "middle" && szof(arrpos) >= 3) {
			int pos = rnd.next(1, szof(arrpos) - 2);
			if (arrpos[pos - 1] < arrpos[pos] - 1 || arrpos[pos] + 1 < arrpos[pos + 1]) {
				arrpos[pos] = rnd_ineq(arrpos[pos - 1] + 1, arrpos[pos + 1] - 1, arrpos[pos]);
				break;
			}
		}
	}

	cout << n << "\n";
	for (int i = 0; i < n; ++i) {
		cout << szof(books[i].ss) << " " << books[i].ff << "\n";
		for (int j = 0; j < szof(books[i].ss); ++j) {
			cout << books[i].ss[j];
			if (j < szof(books[i].ss) - 1) {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}