#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct Time {
    int time;
    int end;
    int idx;
};

void solve() {
    int n = 500;
    cin >> n;
    vector<Time> times(2 * n);
    vector<int> guests(n);
    for (int i = 0; i < n; i++) {
        cin >> times[2 * i].time >> times[2 * i + 1].time;
        times[2 * i].end = 0;
        times[2 * i].idx = i;
        times[2 * i + 1].end = 1;
        times[2 * i + 1].idx = i;
    }

    sort(times.begin(), times.end(), [](const Time& lhs, const Time& rhs) {
        if (lhs.time < rhs.time) return true;
        if (lhs.time > rhs.time) return false;
        if (lhs.end == 1 && rhs.end == 0) return false;
        if (lhs.end == 0 && rhs.end == 1) return true;
        return false;
    });

    int rooms = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        times[i].end == 0 ? rooms++ : rooms--;
        ans = max(ans, rooms);
    }
    cout << ans << "\n";

    set<int> room_ids;
    for (int i = 1; i <= ans; i++) room_ids.insert(i);

    for (int i = 0; i < 2 * n; i++) {
        if (times[i].end == 0) {
            guests[times[i].idx] = *room_ids.begin();
            room_ids.erase(room_ids.begin());
        } else room_ids.insert(guests[times[i].idx]);
    }
    
    for (int i = 0; i < n; i++) cout << guests[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}