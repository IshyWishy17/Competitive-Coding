#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> indices(n);
    for (int i = 0; i < n; i++) { cin >> x[i]; indices[x[i]] = i; }
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (indices[i + 1] > indices[i]) continue;
        rounds++;
    }
    cout << rounds;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}