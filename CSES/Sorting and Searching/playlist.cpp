#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++) cin >> k[i];
    set<int> songs;
    int ans = 1;
    int curr_size = 1;
    int l = 0;
    songs.insert(k[0]);
    for (int i = 1; i < n; i++) {
        if (songs.find(k[i]) == songs.end()) {
            songs.insert(k[i]);
            ans = max(ans, i - l + 1);
        } else { 
            while (k[l] != k[i]) {
                songs.erase(k[l]);
                l++;
            }
            l++;
        }
    }
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}