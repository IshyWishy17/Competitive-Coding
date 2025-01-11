#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << "1\n1\n";
        return;
    }
    if (k == 1 || k == n) {
        cout << "-1\n";
        return;
    }
    int nums_left = k - 1;
    int nums_right = n - k;
    if (min(nums_left, nums_right) == nums_left) {
        int diff = nums_right - nums_left;
        cout << n - diff << "\n";
        int i = 1;
        while (i <= n) {
            if (i <= k || i > k + 1) {
                cout << i << " ";
                i++;
            }
            else if (i == k + 1) {
                cout << i << " ";
                i+= diff + 1;
            }
        }
    } else {
        int diff = nums_left - nums_right;
        cout << n - diff << "\n";
        int i = 1;
        while (i <= n) {
            if (i <= k - diff - 1 || i > k) {
                cout << i << " ";
                i++;
            } else if (i == k - diff) {
                i = k;
                cout << i << " ";
                i++;
            }
        }
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
