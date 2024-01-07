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
	int nodes = opt<int>("nodes");
	int maxs = 1000000000;
	if (__testlib_opts.count("maxs")) {
		maxs = opt<int>("maxs");
	}

	bool is_cycle = false;
	if (__testlib_opts.count("cycle")) {
		is_cycle = true;
	}

	vector<int> arrm(n, 1);
	for (int i = n; i < summ; ++i) {
		int pos = rnd.next(n);
		if (maxs / (arrm[pos] + 2) < nodes - 1) {
			--i;
			continue;
		}
		arrm[pos]++;
	}

	int len = rnd.next(max(1, nodes - 1), maxs / (*max_element(arrm.begin(), arrm.end()) + 1));
	if (__testlib_opts.count("len")) {
		len = opt<int>("len");
	}

	vector<int> node_vals = gen_comb(len + 1, nodes);

	vector<int> seq;
	if (__testlib_opts.count("ends")) {
		int first;
		if (opt<string>("ends")[0] == 's') {
			first = node_vals.front();
			node_vals.erase(node_vals.begin());
		} else {
			first = node_vals.back();
			node_vals.pop_back();
		}
		int last;
		if (opt<string>("ends")[1] == 's') {
			last = node_vals.front();
			node_vals.erase(node_vals.begin());
		} else {
			last = node_vals.back();
			node_vals.pop_back();
		}
		seq.push_back(first);
		for (int i = 1; i < n; ++i) {
			seq.push_back(node_vals[rnd.next(szof(node_vals))]);
		}
		seq.push_back(last);
	} else {
		for (int i = 0; i < n; ++i) {
			seq.push_back(node_vals[rnd.next(nodes)]);
		}
		if (is_cycle) {
			seq.push_back(seq.front());
		} else {
			seq.push_back(node_vals[rnd.next(nodes)]);
		}
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