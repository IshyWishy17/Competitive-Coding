#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, p;
    cin >> n >> p;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    vector<long long int> prefixes(n, arr[0]);
    for (long long int i = 1; i < n; i++) prefixes[i] = prefixes[i - 1] + arr[i];
    long long int max_score = 0;
    for (int i = 0; i < n; i++) {
        max_score = max(max_score, (prefixes[i] % p) + ((prefixes[n - 1] - prefixes[i]) % p));
    }
    cout << max_score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
