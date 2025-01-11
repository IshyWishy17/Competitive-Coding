#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

template <class T> class MaxSegmentTree {
  private:
	const T DEFAULT = 0;

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { return max(a, b); }

	void build(const vector<T> &arr, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = arr[at_left];
			return;
		}
		int mid = (at_left + at_right) / 2;
		build(arr, 2 * at, at_left, mid);
		build(arr, 2 * at + 1, mid + 1, at_right);
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	void set(int ind, T val, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = val;
			return;
		}
		int mid = (at_left + at_right) / 2;
		if (ind <= mid) {
			set(ind, val, 2 * at, at_left, mid);
		} else {
			set(ind, val, 2 * at + 1, mid + 1, at_right);
		}
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	T range_max(int start, int end, int at, int at_left, int at_right) {
		if (at_right < start || end < at_left) { return DEFAULT; }
		if (start <= at_left && at_right <= end) { return segtree[at]; }
		int mid = (at_left + at_right) / 2;
		T left_res = range_max(start, end, 2 * at, at_left, mid);
		T right_res = range_max(start, end, 2 * at + 1, mid + 1, at_right);
		return combine(left_res, right_res);
	}

  public:
	MaxSegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, DEFAULT); };

	MaxSegmentTree(const vector<T> &arr) : len(arr.size()) {
		segtree = vector<T>(len * 4, DEFAULT);
		build(arr, 1, 0, len - 1);
	}

	void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

	T range_max(int start, int end) { return range_max(start, end, 1, 0, len - 1); }
};

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    MaxSegmentTree<long long int> segtree(n);
    for (int i = 0; i < n; i++)
        segtree.set(h[i] - 1, a[i] + segtree.range_max(0, h[i] - 1));
    cout << segtree.range_max(0, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}