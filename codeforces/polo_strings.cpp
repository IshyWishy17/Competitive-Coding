#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, k;
    cin >> n >> k;
    if (k > n) { cout << "-1\n"; return; }
    if (k == n) {
        for (int i = 0; i < n; i++) cout << (char)(i + 'a');
        return;
    }
    if (k == 1) { cout << "-1"; return; }
    for (int i = 0; i < n - k + 2; i++) {
        if (i % 2 == 0) cout << "a";
        else cout << "b";
    }
    for (int i = 0; i < k - 2; i++) cout << (char)(i + 'c');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}
