#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long int> arr(n);
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) { cin >> arr[i]; sum+= arr[i]; }
    if (n <= 2) { cout << "-1\n"; return; }
    sort(arr.begin(), arr.end());
    int ans = max(0LL, (long long int)(2 * n * arr[ceil(n / 2)] - sum + 1LL));
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
