#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    vector<vector<int>> all_salaries;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<int> salaries(m, 0);
        for (int i = 0; i < m; i++) cin >> salaries[i];
        all_salaries.push_back(salaries);
    }
    int max_salary = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < all_salaries[i].size(); j++) {
            max_salary = max(max_salary, all_salaries[i][j]);
        }
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        int max_local = 0;
        for (int j = 0; j < all_salaries[i].size(); j++) {
            max_local = max(max_local, all_salaries[i][j]);
        }
        ans+= (max_salary - max_local) * all_salaries[i].size();
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
