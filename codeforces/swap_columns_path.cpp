#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<long long int> a1(5000);
vector<long long int> a2(5000);

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a1[i];
    for (int i = 0; i < n; i++) cin >> a2[i];
    long long int dp[5001][2];
    dp[0][0] = a1[0] + a2[0];
    dp[0][1] = max(a1[0], a2[0]);
    for (int i = 1; i < n; i++) {
        dp[i][1] = max(a1[i], a2[i]) + dp[i - 1][1];
        dp[i][0] = max(a1[i] + a2[i] + dp[i - 1][1], max(a1[i], a2[i]) + dp[i - 1][0]);
    }
    cout << dp[n - 1][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
