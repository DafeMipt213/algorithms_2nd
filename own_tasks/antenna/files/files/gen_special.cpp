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
	int maxs = 1000000000;
	if (__testlib_opts.count("maxs")) {
		maxs = opt<int>("maxs");
	}

	vector<int> arrm(n, 1);
	if (__testlib_opts.count("add_central")) {
		arrm[rnd.next(n)]++;
	}

	int len = maxs / (*max_element(arrm.begin(), arrm.end()) + 1);

	int maxl = opt<int>("maxl");
	
	int main = rnd.next(len + 1);
	vector<int> seq = {main};
	while (szof(seq) < n + 1) {
		int cur_len;
		do {
			cur_len = rnd.next(maxl) + 1;
		} while (szof(seq) + cur_len > n + 1);

		for (int i = 0; i < cur_len - 1; ++i) {
			seq.push_back(rnd.next(len + 1));
		}
		seq.push_back(main);
	}
	
	vector<pair<pii, vector<int>>> books;

	for (int i = 0; i < n; ++i) {
		int beg = seq[i + 1];
		int end = len - seq[i];
		books.push_back({{arrm[i], beg + end + (arrm[i] - 1) * len}, {}});
		books[i].ss.push_back({beg});
		for (int j = 0; j < arrm[i] - 1; ++j) {
			books[i].ss.push_back(books[i].ss.back() + len);
		}
	}

	shuffle(books.begin(), books.end());

	cout << n << "\n";

	for (auto& book : books) {
		cout << book.ff.ff << " " << book.ff.ss << "\n";
		for (int i = 0; i < book.ff.ff; ++i) {
			cout << book.ss[i];
			if (i < book.ff.ff - 1) {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}