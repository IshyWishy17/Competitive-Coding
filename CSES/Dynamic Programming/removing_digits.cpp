 #include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1);
    dp[0] = 0;
    for (int i = 10; i <= n; i++) {
        vector<int> digits;
        int j = i;
        while (j > 0) {
            digits.push_back(j % 10);
            j /= 10;
        }
        int temp = INT_MAX;
        for (int j = 0; j < digits.size(); j++) {
            if (digits[j] > 0)
                temp = min(temp, dp[i - digits[j]]);
        }
        dp[i] = 1 + temp;
    }

    cout << dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
