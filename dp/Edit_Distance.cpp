#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define nl "\n"
#define mod 1000000007
const int MAX = 5000;

vector<vi> dp(MAX+ 1, vi(MAX + 1));
void solve() {

    string s, t;
    cin >> s >> t;

    int n = s.length(), m = t.length();

    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                // replace the character
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << nl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
