#include <bits/stdc++.h>
using namespace std;

//////////////////////////// basic macros ///////////////////////////////////////////////////////////////

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define nl "\n"
#define pi pair<int, int>
#define pl pair<long long, long long>
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb(a) push_back(a)
#define pp() pop_back()
#define floop(i, start, end) for (int i = start; i < end; ++i)
#define fnloop(i, start, end) for (int i = start; i >= end; --i)

const int MOD = 1e9 + 7;
int dp[100001][101];

int findans(vi& arr, int i, int prev, int x) {
    if (i == arr.size()) return 1;
    if (dp[i][prev] != -1) return dp[i][prev];
    
    int ans = 0;
    if (arr[i] != 0) {
        if (prev == 0 || abs(arr[i] - prev) <= 1)
            ans = findans(arr, i + 1, arr[i], x) % MOD;
    } else {
        for (int j = 1; j <= x; j++) {
            if (prev == 0 || abs(j - prev) <= 1)
                ans = (ans + findans(arr, i + 1, j, x)) % MOD;
        }
    }
    return dp[i][prev] = ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    vi arr(n, 0);
    floop(i, 0, n) cin >> arr[i];

    // memset(dp, -1, sizeof(dp));
    // cout << findans(arr, 0, 0, x) << nl;


    // State -> dp[i][prev]
    vector<vi> dp(n + 1, vi(x + 1, 0));

    if (arr[0] == 0) {
        for (int j = 1; j <= x; j++) dp[0][j] = 1;
    } 
    else {
        dp[0][arr[0]] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (arr[i] != 0 && arr[i] != j) continue;
            dp[i][j] = dp[i - 1][j];
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            if (j < x) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= x; j++) ans = (ans + dp[n - 1][j]) % MOD;
    
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // t--;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}