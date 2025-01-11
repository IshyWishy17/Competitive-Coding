#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int rem = n % 5;
    int each = (n - rem) / 5;
    for (int i = 1; i <= each; i++) cout << "a";
    if (rem > 0) { cout << "a"; rem--; }
    for (int i = 1; i <= each; i++) cout << "e";
    if (rem > 0) { cout << "e"; rem--; }
    for (int i = 1; i <= each; i++) cout << "i";
    if (rem > 0) { cout << "i"; rem--; }
    for (int i = 1; i <= each; i++) cout << "o";
    if (rem > 0) { cout << "o"; rem--; }
    for (int i = 1; i <= each; i++) cout << "u";

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
