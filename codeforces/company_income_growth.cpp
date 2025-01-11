#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> years;
    for (int i = 0; i < n; i++) cin >> a[i];
    int curr_number = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == curr_number) {
            curr_number++;
            years.push_back(2000 + i + 1);
        }
    }
    cout << years.size() << "\n";
    for (int i = 0; i < years.size(); i++) {
        cout << years[i] << " ";
        if (i == years.size() - 1) cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
