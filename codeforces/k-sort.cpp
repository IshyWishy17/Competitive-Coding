#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void solve() {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (arr.size() == 1) {
        cout << (m / arr[0]) * arr[0] << "\n";
        return;
    }
    long long int i = 0;
    while (i < n) {
        long long int money = m;
        long long int petals = 0;
        petals+= (m / arr[0]) * arr[0]
        while (arr[i] == arr[i + 1] && money >= 0) {
            
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
