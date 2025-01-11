#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    // 1. If there exists an index i (0 <= i < n - 1) such that 0 ... prefix_sum(i) is achievable and x[i + 1] > prefix_sum(i) + 1, then prefix_sum(i) + 1 is not achievable.
    // The answer is prefix_sum(i) + 1
    // 2. There is exactly one such index i (i = n - 1 always works).
    // 3. Consider such an i, our algorithm will output prefix_sum(i) + 1. Let us call this value S.
    // 4. Why is S optimal? 
    // Call true OPT X. X cannot be greater than S (optimality of X)
    // X cannot be less than S either (correctness of X)
    long long int s = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] > s + 1) { cout << s + 1; return; }
        s+= x[i];
    }
    cout << s + 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}