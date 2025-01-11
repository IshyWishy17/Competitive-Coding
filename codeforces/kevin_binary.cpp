#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool check_greater(string s1, string s2) {
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '0' && s2[i] == '1') return false;
        if (s1[i] == '1' && s2[i] == '0') return true;
    }
    return false;
}

string compute_xor(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    string s = s2;
    int x = n1 - 1;
    for (int i = n2 - 1; i >= n2 - n1; i--) {
        if (s1[x] == s2[i]) s[i] = '0';
        else s[i] = '1';
        x--;
    }
    return s;
}


void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int idx = -1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << 1 << " " << 1 << " " << 1 << " " << n << "\n";
        return;
    }
    int k = n - idx;
    int l = 0;
    string s1 = compute_xor(s.substr(0, k), s);
    for (int i = 0; i + k - 1 < n; i++) {
        if (i == idx) continue;
        string s2 = compute_xor(s.substr(i, k), s);
        if (check_greater(s2, s1)) {
            s1 = s2;
            l = i;
        }
    }
    l++;
    cout << 1 << " " << n << " " << l << " " << l + k - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
