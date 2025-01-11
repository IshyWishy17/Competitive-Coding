#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        times.push_back(make_pair(start, 0));
        times.push_back(make_pair(end, 1));
    }
    sort(times.begin(), times.end());
    int ans = 0;
    int people = 0;
    for (int i = 0; i < 2 * n; i++) {
        times[i].second == 0 ? people++ : people--;
        ans = max(ans, people);
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