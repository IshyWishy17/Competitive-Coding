#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    for (long long int i = 1; i < n; i+= 2) {
        if (k > 0) {
            if (arr[i] + k <= arr[i - 1]) { arr[i]+= k; k = 0; }
            else { arr[i] = arr[i - 1]; k-= arr[i - 1] - arr[i]; }
        }
    }
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
        if (i % 2 == 0) ans+= arr[i];
        else ans-= arr[i];
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
