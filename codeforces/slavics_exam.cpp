#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    long long int n = s.length();
    long long int j = 0;
    for (long long int i = 0; i < n; i++) {
        if (j == t.length() && s[i] == '?') s[i] = 'a';
        if (s[i] == t[j]) j++;
        if (s[i] == '?') { s[i] = t[j]; j++; }
    }
    if (j == t.length()) { cout << "YES\n" << s << "\n"; }
    else cout << "NO\n"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
