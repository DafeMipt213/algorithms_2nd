// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	int len = -1;
	vector<pii> arr;
	for (int i = 0; i < n; ++i) {
		int m, s;
		cin >> m >> s;
		vector<int> cur;
		for (int j = 0; j < m; ++j) {
			int pos;
			cin >> pos;
			cur.push_back(pos);
		}

		for (int j = 0; j < m - 1; ++j) {
			if (len == -1) {
				len = cur[j + 1] - cur[j];
			} else {
				if (len != cur[j + 1] - cur[j]) {
					cout << "No\n";
					return;
				}
			}
		}

		arr.push_back({cur[0], s - cur.back()});
	}

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);

	do {
		int cur_len = len;
		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			int val = arr[order[i]].ss + arr[order[i + 1]].ff;
			if (cur_len == -1) {
				cur_len = val;
			} else {
				if (cur_len != val) {
					ok = false;
					break;
				}
			}
		}

		if (ok) {
			cout << "Yes\n";
			for (int ind : order) {
				cout << ind + 1 << " ";
			}
			cout << "\n";
			return;
		}
	} while (next_permutation(order.begin(), order.end()));

	cout << "No\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}