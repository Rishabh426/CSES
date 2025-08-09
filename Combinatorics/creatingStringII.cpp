#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define N 1000000
ll fact[N + 1], inv_fact[N + 1];

ll power(ll x, ll y, ll mod) {
    ll res = 1;
    while (y) {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[N] = power(fact[N], MOD - 2, MOD);
    for (int i = N - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll solve(string s) {
    ll mx = 1, n = s.length();
    map<char, int> mpp;
    for(auto &c : s) mpp[c]++;
    for(auto &[x, y] : mpp) mx = mx % MOD * inv_fact[y] % MOD;
    return fact[n] * mx % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute();

    string s;
    cin >> s;
    cout << solve(s) << "\n";

    return 0;
}
