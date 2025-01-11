#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    string s;
    cin >> n;
    cin >> s;
    string sRG = s;
    string sRB = s;
    string sGB = s;
    string sGR = s;
    string sBG = s;
    string sBR = s;
    long long int rg = 0, rb = 0, gb = 0, gr = 0, bg = 0, br = 0;
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            sRG[i] = 'R';
            sRB[i] = 'R';
            sGB[i] = 'G';
            sGR[i] = 'G';
            sBG[i] = 'B';
            sBR[i] = 'B';
        }
        if (i % 3 == 1) {
            sRG[i] = 'G';
            sRB[i] = 'B';
            sGB[i] = 'B';
            sGR[i] = 'R';
            sBG[i] = 'G';
            sBR[i] = 'R';
        }
        if (i % 3 == 2) {
            sRG[i] = 'B';
            sRB[i] = 'G';
            sGB[i] = 'R';
            sGR[i] = 'B';
            sBG[i] = 'R';
            sBR[i] = 'G';
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != sRG[i]) rg++;
        if (s[i] != sRB[i]) rb++;
        if (s[i] != sGB[i]) gb++;
        if (s[i] != sGR[i]) gr++;
        if (s[i] != sBG[i]) bg++;
        if (s[i] != sBR[i]) br++;
    }

    long long int ans = min({ rg, rb, gb, gr, bg, br });
    cout << ans << "\n";

    if (ans == rg) cout << sRG;
    else if (ans == rb) cout << sRB;
    else if (ans == gb) cout << sGB;
    else if (ans == gr) cout << sGR;
    else if (ans == bg) cout << sBG;
    else if (ans == br) cout << sBR;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
