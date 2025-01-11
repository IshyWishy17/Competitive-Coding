#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 1, 3^2, 5^2, 7^2
    int days = 0;
    int start = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+= a[i];
        int block = (int)sqrt(sum);
        if (block * block == sum && block % 2 == 1) days++;
    }
    cout << days << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
