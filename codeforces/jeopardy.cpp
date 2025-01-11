#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, n;
    cin >> n >> m;
    vector<long long int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    long long int normal_sum = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 == b[j]) {
            j++;
            continue;
        }
        normal_sum+= a[i];
    }
    priority_queue<long long int> pq;
    for (int i = 0; i < m; i++) {
        pq.push(a[b[i] - 1]);
    }
    long long int ans = normal_sum;
    while (!pq.empty()) {
        long long int smallest = pq.top();
        if (smallest >= ans) ans+= smallest;
        else ans*= 2;
        pq.pop();
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
