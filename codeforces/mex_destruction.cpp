#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) flag = false;  
    }
    if (flag) { cout << "0\n"; return; }
    int l = 0;
    int r = n - 1;
    while (a[l] == 0) l++;
    while (a[r] == 0) r--;
    flag = false;
    for (int i = l + 1; i < r; i++) {
        if (a[i] == 0) flag = true;
    }
    if (!flag) {
        cout << "1\n";
        return;
    }
    cout << "2\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
