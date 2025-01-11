#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    long long int total_sum = 0;
    for (long long int i = 0; i < n; i++) total_sum+= arr[i];
    vector<long long int> indices;
    for (long long int i = 0; i < n; i++) {
        if (total_sum - arr[i] == arr[i] * (n - 1)) indices.push_back(i + 1);
    }
    cout << indices.size() << "\n";
    for (long long int i = 0; i < indices.size(); i++) cout << indices[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
