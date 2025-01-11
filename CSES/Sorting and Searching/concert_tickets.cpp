#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        h.insert(temp);
    }
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 0; i < m; i++) {
        if (t.size() == 0) {
            cout << "-1\n";
            continue;
        }
        auto it = upper_bound(h.begin(), h.end(), t[i]);
        if (it == h.begin()) {
            cout << "-1\n";
            continue;
        }
        cout << *(--it) << "\n";
        h.erase(it);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}