#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long int> k(n);
    for (int i = 0; i < n; i++) cin >> k[i];
    multiset<long long int> towers;
    for (int i = 0; i < n; i++) {
        auto it = towers.upper_bound(k[i]);
        if (it == towers.end()) {
            towers.insert(k[i]);
        } else {
            long long int x = *it;
            towers.erase(it);
            towers.insert(k[i]);
        }
    }
    cout << towers.size();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}