#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    stack<int> s;
    s.push(1);
    cout << "0 ";
    for (int i = 1; i < n; i++) {
        if (x[s.top() - 1] < x[i]) {
            cout << s.top() << " ";
        } else {
            while (!s.empty() && x[s.top() - 1] >= x[i]) s.pop();
            if (s.empty()) cout << "0 ";
            else cout << s.top() << " ";
        }
        s.push(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}