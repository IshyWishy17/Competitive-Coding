#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> counts(2000, 0);
    vector<pair<int, int>> sorted;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        counts[h[i] - 1]++;
        sorted.push_back(make_pair(h[i], i));
    }
    bool flag = false;
    int c = 0;
    for (int i = 0; i < 2000; i++) {
        if (counts[i] >= 3) { flag = true; break; }
        if (counts[i] >= 2) {
            c++;
            if (c == 2) { flag = true; break; }
        }
    }
    if (!flag) {
        cout << "NO";
        return;
    }
    sort(sorted.begin(), sorted.end());

    cout << "YES\n";

    for (int i = 0; i < n; i++) cout << sorted[i].second + 1 << " ";
    cout << "\n";

    c = 0;
    for (int i = 0; i < n; i++) {
        if (c == 0 && i < n - 1 && sorted[i].first == sorted[i + 1].first) {
            swap(sorted[i], sorted[i + 1]);
            c++;
        }
        cout << sorted[i].second + 1 << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        if (i < n - 1 && sorted[i].first == sorted[i + 1].first) {
            swap(sorted[i], sorted[i + 1]);
        }
        cout << sorted[i].second + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
