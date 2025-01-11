#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<double, double>> points(n);
    set<pair<double, double>> points_set;
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
    for (int i = 0; i < n; i++) points_set.insert(points[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            pair<double, double> mid = make_pair((points[i].first + points[j].first) / 2, (points[i].second + points[j].second) / 2);
            if (points_set.find(mid) != points_set.end()) ans++;
        }
    }

    cout << ans / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
