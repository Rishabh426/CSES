#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1000
#define mod 1000000000

ll dp[N + 1][N + 1];

void precompute() {
    
    for(int i = 0; i <= N; i++) {
        dp[i][0] = dp[i][i] = 1;
        for(int j = 0; j < i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] % mod;
        }
    }
    return;
}
ll nCr(ll a, ll b) {
    return dp[a][b];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << nCr(a, b) << "\n";
    }
    return 0;
}