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

ll nCr(int n, int r) {
    if (r > n || r < 0)
        return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
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
