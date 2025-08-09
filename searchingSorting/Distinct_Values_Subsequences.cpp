#include <bits/stdc++.h>
using namespace std;

//////////////////////////// basic macros ///////////////////////////////////////////////////////////////

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define nl "\n" 
#define floop(i, start, end) for (int i = start; i < end; ++i)
#define fnloop(i, start, end) for (int i = start; i >= end; --i)

const ll mod = 1e9 + 7;

ll power(ll base, ll exponent, ll mod) {
    ll result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<int, int> last_occurrence;
    vll dp(n + 1); 

    dp[0] = 1; 

    floop(i, 1, n + 1) {
        dp[i] = (2 * dp[i - 1]) % mod;

        if (last_occurrence.count(a[i - 1])) {
            int j = last_occurrence[a[i - 1]];
            dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
        }

        last_occurrence[a[i - 1]] = i;
    }

    ll result = (dp[n] - 1 + mod) % mod; 
    cout << result << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}