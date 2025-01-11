#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    set<int> bag;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bag.insert(x);
    }
    cout << bag.size();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}