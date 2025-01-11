#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int apt = 0;
    int i = 0;
    int count = 0;
    while (i < n) {
        if (apt == m) break;
        if (abs(a[i] - b[apt]) <= k) {
            apt++;
            i++;
            count++;
        }
        else if (a[i] > b[apt]) apt++;
        else i++;
    }
    cout << count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}