#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    long long int sum = 0;
    for (int i = 0; i < n; i++) sum+= x[i];
    vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = x[i];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
        }
    }
    cout << (sum + dp[0][n - 1]) / 2;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}