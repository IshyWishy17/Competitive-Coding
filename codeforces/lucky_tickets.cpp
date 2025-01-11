#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(3, 0);
    for (int i = 0; i < n; i++) {
        long long int num;
        cin >> num;
        a[num % 3]++;
    }
    int ans = a[0] / 2 + min(a[1], a[2]);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}
