#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void solve() {
    long long int w, b;
    cin >> w >> b;
    long long int n = 0;
    while ((n * (n + 1)) / 2 < w + b) n++;
    cout << ((n * (n + 1)) / 2 == w + b ? n : n - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
