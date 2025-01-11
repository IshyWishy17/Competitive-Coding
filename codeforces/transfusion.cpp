#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long int sum = 0;
    for (int i = 0; i < n; i++) sum+= a[i];
    if ((sum / n) * n != sum) {
        cout << "NO\n";
        return;
    }
    long long int avg = sum / n;
    for (int i = 1; i < n - 1; i++) {
        a[i + 1]+= a[i - 1] - avg;
        a[i - 1] = avg;
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != avg) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
