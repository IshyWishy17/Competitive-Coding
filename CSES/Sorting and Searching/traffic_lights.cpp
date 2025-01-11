#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    multiset<int> lights;
    multiset<int> distances;
    distances.insert(x);
    lights.insert(0);
    for (int i = 0; i < n; i++) {
        auto it = lights.upper_bound(p[i]);
        auto other_it = it;
        int old_distance;
        if (it == lights.end()) old_distance = x - *(--lights.end());
        else if (it == ++lights.begin()) old_distance = *it;
        else old_distance = *it - *(--it);
        int d1;
        if (other_it == lights.end()) d1 = x - p[i];
        else d1 = *other_it - p[i];
        int d2 = p[i] - *(--other_it);
        distances.erase(distances.find(old_distance));
        distances.insert(d1);
        distances.insert(d2);
        cout << *(--distances.end()) << " ";
        lights.insert(p[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}