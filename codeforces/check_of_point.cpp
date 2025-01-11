#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, x, y;
    cin >> a >> x >> y;
    if (x < 0 || y < 0 || x > a || y > a) { cout << "2\n"; return; }
    if (x > 0 && x < a && y > 0 && y < a) { cout << "0\n"; return; }
    cout << "1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
