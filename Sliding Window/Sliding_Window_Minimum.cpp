#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define nl "\n"
#define pi pair<int, int>
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb(a) push_back(a)
#define f(i, start, end) for (int i = start; i < end; ++i)
#define inf 1e9
const int mod = 1e9 + 7;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        f(i,0,n) parent[i] = i;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
};

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b)/ (gcd(a, b));
}

void solve() {
    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vll arr(n);
    arr[0] = x;

    f(i, 1, n) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    deque<ll> dq;
    ll ans = 0;

    for (ll i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] >= arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1) {
            ans ^= arr[dq.front()];
        }
    }

    cout << ans << nl;
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}