#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

long long int get_sqrt(long long int x) {
    long long int start = 0;
    long long int end = 2e9;
    while (start < end) {
        long long int k = (start + end + 1) / 2;
        if (k * k <= x) start = k;
        else end = k - 1;
    }
    return start;
}
 
void solve() {
    long long int k;
    cin >> k;
    long long int jump = 1;
    while (jump <= 2 * k) jump*= 2;
    // Look between k and 2k inclusive for first occurrence of target == k + sqrt(target) 
    // Keep jumping as long as target < k + sqrt(target)
    long long int start = k;
    for (long long int j = jump; j >= 1;) {
        if (start + j < k + get_sqrt(start + j)) {
            start+= j;
            j = jump;
        }
        else j/= 2;
    }
    cout << start + 1 << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}