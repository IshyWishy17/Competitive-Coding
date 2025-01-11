#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> counts(26, 0);
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        counts[idx]++;
    }
    int mx = 0;
    int mn = n + 1;
    int cmax = -1;
    int cmin = -1;
    int cmax_diff = -1;
    for (int i = 25; i >= 0; i--) {
        if (counts[i] > mx) {
            mx = counts[i];
            cmax_diff = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0 && counts[i] < mn) {
            mn = counts[i];
            cmin = i;
        }
    }
    if (counts[cmax] == n) {
        cout << s << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] - 'a' == cmin) {
            s[i] = (char)('a' + cmax_diff);
            cout << s << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
