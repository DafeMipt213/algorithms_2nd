// Checker created by Nikolay Budin

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

int main(int argc, char* argv[]) {
	setName("compare two outputs");
	registerTestlibCmd(argc, argv);

	int n = inf.readInt();
	vector<pair<vector<int>, int>> books;
	for (int i = 0; i < n; ++i) {
		int m = inf.readInt();
		int s = inf.readInt();
		vector<int> cur;
		for (int j = 0; j < m; ++j) {
			int pos = inf.readInt();
			cur.push_back(pos);
		}
		books.push_back({cur, s});
	}

	auto check_outp = [&](auto& stream) {
		string outcome = stream.readToken("Yes|No");
		if (outcome == "No") {
			return false;
		}

		vector<int> order;
		for (int i = 0; i < n; ++i) {
			order.push_back(stream.readInt(1, n) - 1);
		}

		stream.ensuref(set<int>(order.begin(), order.end()).size() == (uint32_t) n, "not a permutation");

		vector<ll> arr_pos;
		ll sum = 0;
		for (int ind : order) {
			for (int pos : books[ind].ff) {
				arr_pos.push_back(sum + pos);
			}
			sum += books[ind].ss;
		}

		ll dist = -1;

		for (int i = 0; i < szof(arr_pos) - 1; ++i) {
			if (i == 0) {
				dist = arr_pos[i + 1] - arr_pos[i];
			} else {
				stream.ensuref(dist == arr_pos[i + 1] - arr_pos[i], 
					"distance between bookmarks #%d and #%d differs from distance between first and second bookmarks", i + 1, i + 2);
			}
		}

		return true;
	};

	bool jans = check_outp(ans);
	bool pans = check_outp(ouf);

	if (!pans && jans) {
		quitf(_wa, "participant didn't find solution, but it exists");
	}

	if (!jans && pans) {
		quitf(_fail, "jury didn't find solution, but it exists");
	}

	if (!pans) {
		quitf(_ok, "no solution");
	}

	quitf(_ok, "solution was found");

	return 0;
}