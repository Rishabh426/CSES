#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define nl "\n"
const int mod = 1e9 + 7;
const int MAX = 1000;

int dp[MAX + 1][MAX + 1];

int findans(vector<vector<char>>& grid, int n, int m) {

    if(n == 0 && m == 0 && grid[n][m] != '*') return 1;
    if(n < 0 || m < 0) return 0;
    if(grid[n][m] == '*') return 0;
    if(dp[n][m] != -1) return dp[n][m];

    int u = findans(grid, n - 1, m);
    int l = findans(grid, n, m - 1);

    return dp[n][m] = (u + l) % mod;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n, '.'));
    for(auto &c : grid) {
        for(auto &it : c) cin >> it;
    }

    memset(dp, -1, sizeof(dp));
    cout << findans(grid, n - 1, n - 1) << nl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
