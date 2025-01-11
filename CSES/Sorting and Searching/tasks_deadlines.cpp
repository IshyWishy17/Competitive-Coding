#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<long long int, long long int>> tasks(n);
    for (int i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());
    long long int ans = 0;
    long long int time = 0;
    for (int i = 0; i < n; i++) {
        time += tasks[i].first;
        ans += tasks[i].second - time;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}