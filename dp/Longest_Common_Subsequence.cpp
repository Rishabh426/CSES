#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define nl "\n"
#define mod 1000000007
const int MAX = 1000;

vector<vi> dp(MAX+ 1, vi(MAX + 1, 0));
void solve() {

    int n, m;
    cin >> n >> m;

    vi arr(n), brr(m);
    for(auto &c : arr) cin >> c;
    for(auto &c : brr) cin >> c;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(arr[i - 1] == brr[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << nl;
    
    vi ans(dp[n][m], 0);
    int k = dp[n][m];
    --k;

    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(arr[i - 1] == brr[j - 1]) {
            ans[k] = arr[i - 1];
            --i;
            --j;
            --k;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }

    for(auto &c : ans) cout << c << " ";
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
