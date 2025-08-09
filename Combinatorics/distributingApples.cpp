#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
const int N = 2e6 + 7;

ll fact[N], inv_fact[N];

ll power(ll x, ll y) {
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
    for (int i = 2; i < N; i++)
        fact[i] = fact[i - 1] * i % mod;
    inv_fact[N-1] = power(fact[N-1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}

ll nCr(int n, int m) {
    if (m == 0) return 1;
    return fact[n + m - 1] * inv_fact[n - 1] % mod * inv_fact[m] % mod;
}

ll solve(ll a, ll b) {
    return nCr(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}