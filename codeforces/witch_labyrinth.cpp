#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool dfs(int n, int m, int i, int j, vector<string>& maze, vector<string>& escapes) {
    if (escapes[i][j] == 'T') return true;
    if (escapes[i][j] == 'F') return false;
    if (escapes[i][j] == 'V') { escapes[i][j] = false; return false; }

    escapes[i][j] = 'V';

    if (maze[i][j] == 'U') {
        if (i == 0) { escapes[i][j] = 'T'; return true; }
        dfs(n, m, i - 1, j, maze, escapes) ? escapes[i][j] = 'T' : escapes[i][j] = 'F';
    }
    if (maze[i][j] == 'D') {
        if (i == n - 1) { escapes[i][j] = 'T'; return true; }
        dfs(n, m, i + 1, j, maze, escapes) ? escapes[i][j] = 'T' : escapes[i][j] = 'F';
    }
    if (maze[i][j] == 'L') {
        if (j == 0) { escapes[i][j] = 'T'; return true; }
        dfs(n, m, i, j - 1, maze, escapes) ? escapes[i][j] = 'T' : escapes[i][j] = 'F';
    }
    if (maze[i][j] == 'R') {
        if (j == m - 1) { escapes[i][j] = 'T'; return true; }
        dfs(n, m, i, j + 1, maze, escapes) ? escapes[i][j] = 'T' : escapes[i][j] = 'F';
    }

    return escapes[i][j] == 'T' ? true : false;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n, string(m, 'X'));
    vector<string> escapes(n, string(m, 'X'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            maze[i][j] = c;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (maze[i][j] != '?') continue;

            if (i > 0 && (maze[i - 1][j] == 'D' || maze[i - 1][j] == '?')) {
                escapes[i][j] = 'F';
                escapes[i - 1][j] = 'F';
            }
            else if (i + 1 < n && (maze[i + 1][j] == 'U' || maze[i + 1][j] == '?')) {
                escapes[i][j] = 'F';
                escapes[i + 1][j] = 'F';
            }
            else if (j > 0 && (maze[i][j - 1] == 'R' || maze[i][j - 1] == '?')) {
                escapes[i][j] = 'F';
                escapes[i][j - 1] = 'F';
            }
            else if (j + 1 < m && (maze[i][j + 1] == 'L' || maze[i][j + 1] == '?')) {
                escapes[i][j] = 'F';
                escapes[i][j + 1] = 'F';
            }
        }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(n, m, i, j, maze, escapes);
        }
    }
    
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (escapes[i][j] == 'F') ans++;
            if (escapes[i][j] == 'V') {
                if (i > 0 && escapes[i - 1][j] == 'F') ans++;
                else if (i + 1 < n && escapes[i + 1][j] == 'F') ans++;
                else if (j > 0 && escapes[i][j - 1] == 'F') ans++;
                else if (j + 1 < m && escapes[i][j + 1] == 'F') ans++;
            }
        }
    }
    cout << ans << "\n";       
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
