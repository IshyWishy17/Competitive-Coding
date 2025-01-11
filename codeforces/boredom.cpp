#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    vector<long long int> counts(1e5 + 1);
    vector<long long int> dp(1e5 + 5, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        counts[arr[i]]++;
    }
    for (int i = 1e5; i >= 1; i--) {
        dp[i] = max(dp[i + 1], counts[i] * i + dp[i + 2]);
    }
    cout << dp[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
