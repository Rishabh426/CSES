#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define nl "\n"
const int mod = 1e9 + 7;
const int MAX = 1e6;

int dp[MAX + 1];

int findans(vi &arr, int n, int x) {
    
    if (x == 0) return 1;
    if (x < 0) return 0;
    if (dp[x] != -1) return dp[x];
    
    int ways = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= x) {
            ways = (ways + findans(arr, n, x - arr[i])) % mod;
        }
    }
    
    return dp[x] = ways;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vi arr(n);
    for (auto &c : arr) cin >> c;

    memset(dp, -1, sizeof(dp));  
    cout << findans(arr, n, m) << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
