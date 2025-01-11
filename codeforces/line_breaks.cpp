#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> a(n);
    vector<string> strings;
    string s;
    long long int ans = 0;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        strings.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        sum+= strings[i].length();
        if (sum > m) {
            break;
        }
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
