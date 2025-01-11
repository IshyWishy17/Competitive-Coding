#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> bits(2 * n, 0);
    vector<int> counts(2 * n, 0);
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) cin >> intervals[i].first >> intervals[i].second;
    for (int i = 0; i < n; i++) {
        if (intervals[i].first == intervals[i].second) {
            counts[intervals[i].first - 1]++;
            bits[intervals[i].first - 1] = 1;
        }
    }
    vector<int> prefixes(2 * n, bits[0]);
    for (int i = 1; i < 2 * n; i++) prefixes[i] = prefixes[i - 1] + bits[i];    
    for (int i = 0; i < n; i++) {
        if (intervals[i].first == intervals[i].second) {
            if (counts[intervals[i].first - 1] > 1) cout << "0";
            else cout << "1";
            continue;
        }
        if (intervals[i].first == 1) {
            if (prefixes[intervals[i].second - 1] == intervals[i].second) {
                cout << "0";
            } else cout << "1";
            continue;
        }
        if (prefixes[intervals[i].second - 1] - prefixes[intervals[i].first - 2] == intervals[i].second - intervals[i].first + 1) {
            cout << "0";
        }
        else cout << "1";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
