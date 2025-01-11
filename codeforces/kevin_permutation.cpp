#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n, 0);
    set<int> nums;
    for (int i = 1; i <= n; i++) nums.insert(i);
    int c = 1;
    for (int i = k - 1; i < n; i+=k) {
        p[i] = c;
        nums.erase(c);
        c++; 
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            p[i] = *nums.begin();
            nums.erase(nums.begin());
        }
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
