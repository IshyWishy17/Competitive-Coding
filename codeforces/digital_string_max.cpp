#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    string num;
    vector<int> a;
    cin >> num;
    n = num.length();
    for (char c : num) a.push_back(c - '0');
    for (int i = 1; i < n; i++) {
        int x = i;
        while (x > 0 && a[x] - 1 > a[x - 1]) {
            int temp = a[x] - 1;
            a[x] = a[x - 1];
            a[x - 1] = temp;
            x--;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i];
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
