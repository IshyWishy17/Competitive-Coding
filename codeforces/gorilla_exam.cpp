#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> m;
    for (int i = 0; i < n; i++) m[a[i]]++;
    multiset<int> s;
    for (auto& pair : m) s.insert(pair.second);
    int x = s.size();
    if (x == 1) {
        cout << "1\n";
        return;
    }
    int c = 0;
    for (int e : s) {
        if (e <= k) {
            c++;
            k -= e;
        }

    }
    cout << max(1, x - c) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
