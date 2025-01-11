#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    long long int s = 0;
    for (int i = 0; i < n; i++) { cin >> a[i]; s+= a[i]; }
    long long int avg = s / n;
    cout << ((avg * n) == s ? n : n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
