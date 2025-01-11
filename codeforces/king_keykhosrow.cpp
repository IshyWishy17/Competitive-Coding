#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int m = min(a, b);
    while (true) {
        if (m % a == m % b) { cout << m << "\n"; break; }
        m++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
