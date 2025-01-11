#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int arr [n][n];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int ans = 0;
    for (int k = 0; k < n; k++) {
        int min_main = numeric_limits<int>::infinity(); 
        for (int i = 0; i + k < n; i++)
            min_main = min(min_main, arr[i][i + k]);
        if (min_main < 0) ans = ans - min_main;
    }

    for (int k = 1; k < n; k++) {
        int min_main = numeric_limits<int>::infinity(); 
        for (int i = 0; i + k < n; i++)
            min_main = min(min_main, arr[i + k][i]);
        if (min_main < 0) ans = ans - min_main;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
