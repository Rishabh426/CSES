#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define nl "\n"
const int mod = 1e9 + 7;
const int MAX = 1e6;

int findans(vi &arr, int n, int x, vector<vector<int>>& dp) {
    
    if (x == 0) return 1;
    if(n < 0 || x < 0) return 0;
    if (dp[n][x] != -1) return dp[n][x];
    
    int nx = findans(arr, n - 1, x, dp);
    int mx = 0;
    if(x - arr[n] >= 0) mx = findans(arr, n, x - arr[n], dp);
    return dp[n][x] = (mx + nx) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vi arr(n);
    for (auto &c : arr) cin >> c;
    
    vector<vi> dp(n, vi(MAX + 1, -1));
    cout << findans(arr, n - 1, m, dp) << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
