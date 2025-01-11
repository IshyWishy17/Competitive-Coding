#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve (int t) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long int rounds = 0; 
    long long int pressed = 0;
    long long int cans = 0;
    for (long long int i = 0; i < n;) {
        if (cans + ((arr[i] - rounds) * (n - i)) >= k) {
            pressed+= k - cans;
            cout << pressed << "\n";
            break;
        } else {
            pressed+= (arr[i] - rounds) * (n - i);
            cans+= (arr[i] - rounds) * (n - i);
            rounds+= arr[i];
            i++;
            pressed++;
            while (i < n && arr[i] == arr[i - 1]) { i++; pressed++; }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(t);
}
