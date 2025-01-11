#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (abs(arr[i] - arr[i + 1]) != 5 && abs(arr[i] - arr[i + 1]) != 7) flag = false;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
