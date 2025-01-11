#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m, k;
    cin >> m >> k;
    vector<int> d(m);
    vector<int> s(m);
    for (int i = 0; i < m; i++) cin >> d[i];
    for (int i = 0; i < m; i++) cin >> s[i];
    int max_fuel = 0;
    int curr_fuel = 0;
    int time = 0;
    for (int i = 0; i < m; i++) {
        curr_fuel+= s[i];
        max_fuel = max(max_fuel, s[i]);
        if (curr_fuel >= d[i]) {
            curr_fuel-= d[i];
            time+= d[i];
        } else {
            double fuel_needed = d[i] - curr_fuel;
            int times = ceil(fuel_needed / max_fuel);
            curr_fuel+= max_fuel * times;
            time+= k * times;
            curr_fuel-= d[i];
            time+= d[i];
        }
    }

    cout << time << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}
