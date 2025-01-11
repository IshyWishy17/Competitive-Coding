#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, m;
    cin >> n >> m;
    int t;
    vector<int> arr(m + n);
    vector<int> riders;
    vector<int> drivers;
    vector<int> closest(m, 0);
    for (long long int i = 0; i < m + n; i++)
        cin >> arr[i];
    for (long long int i = 0; i < m + n; i++)
    {
        cin >> t;
        if (t == 0)
            riders.push_back(arr[i]);
        else
            drivers.push_back(arr[i]);
    }
    long long int j = 0;
    for (long long int i = 0; i < n; i++)
    {
        while (j + 1 < m && drivers[j + 1] < riders[i])
            j++;
        if ((j == 0 && riders[i] < drivers[j]) || (j == m - 1 && riders[i] > drivers[j]))
        {
            closest[j]++;
            continue;
        }
        if (riders[i] - drivers[j] <= drivers[j + 1] - riders[i])
        {
            closest[j]++;
        }
        else
            closest[j + 1]++;
    }

    for (long long int i = 0; i < m; i++)
    {
        cout << closest[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
