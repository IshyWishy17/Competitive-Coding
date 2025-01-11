#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> odds;
    odds.push_back(1);
    if (n >= 3 || d == 3 || d == 6 || d == 9) odds.push_back(3);
    if (d == 5) odds.push_back(5);
    if (d == 7 || n >= 3) odds.push_back(7);
    if (n >= 6 || d == 9 || (n >= 3 && d == 3) || (n >= 3 && d == 6)) odds.push_back(9);
    for (int i = 0; i < odds.size(); i++) cout << odds[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
