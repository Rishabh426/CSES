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

    ll n;
    cin >> n;

    queue<ll> q;
    floop(i, 1, n + 1) q.push(i);

    while(!q.empty()) {
        ll top = q.front();
        q.pop();
        if(q.empty()) {
            cout << top << nl;
            return;
        }
        cout << q.front() << " ";
        q.pop();
        q.push(top);
    }

    cout << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}