#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    long long int min_x, max_x, min_y, max_y;
    min_x = 1e9;
    min_y = 1e9;
    max_x = -1e9;
    max_y = -1e9;
    for (int i = 0; i < n; i++) {
        long long int x, y;
        cin >> x >> y;
        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    long long int side = max(max_x - min_x, max_y - min_y);
    cout << side * side;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
