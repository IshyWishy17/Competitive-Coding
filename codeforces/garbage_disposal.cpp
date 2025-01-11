#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    double k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long int bags = 0;
    for (int i = 1; i < n; i++) {
        long long int min_bags = ceil(a[i - 1] / k);
        bags+= min_bags;
        long long int extra_space = k * min_bags - a[i - 1];
        a[i]-= extra_space;
        a[i] = max(a[i], 0.0);
    }
    bags+= ceil(a[n - 1] / k);
    cout << bags << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
