#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    string num;
    cin >> num;
    n = num.length();
    vector<vector<bool>> dp (n + 1, vector<bool> (9, false));
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; i--)
        for (int mod = 0; mod < 9; mod++)
            if (((num[i] - '0') != 2) && ((num[i] - '0') != 3)) dp[i][mod] = dp[i + 1][(mod + (num[i] - '0')) % 9];
            else dp[i][mod] = dp[i + 1][(mod + (num[i] - '0')) % 9] || dp[i + 1][(mod + (num[i] - '0') * (num[i] - '0')) % 9];
    bool ans = dp[0][0];
    ans == true ? cout << "YES\n" : cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
