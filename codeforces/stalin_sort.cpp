#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = n;
    for (int i = 0; i < n; i++) {
        int thrown = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[i]) thrown++;
        if (thrown < ans) ans = thrown;
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
