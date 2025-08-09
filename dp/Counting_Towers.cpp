#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define nl "\n"
#define mod 1000000007
const int MAX = 1e6;

vector<vi> dp(MAX+ 1, vi(2));
void solve() {

    int n;
    cin >> n;

    dp[n][0] = 1;
    dp[n][1] = 1;

    for(int i = n - 1; i >= 0; i--) {
        dp[i][0] = (2LL * dp[i + 1][0] + dp[i + 1][1]) % mod;
        dp[i][1] = (4LL * dp[i + 1][1] + dp[i + 1][0]) % mod;
    }

    cout << (dp[1][0] + dp[1][1]) % mod << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    --t;
    while(t--) solve();
    solve();
    return 0;
}
