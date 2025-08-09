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

class DSU
{
public:
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n);
        f(i, 0, n) parent[i] = i;
    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
};

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / (gcd(a, b));
}

void dfs(int node, vector<vi>& adj, vi& vis) {

    vis[node] = 1;
    for(auto &c : adj[node]) {
        if(!vis[c]) {
            dfs(c, adj, vis);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n + 1);
    f(i, 0, m) {
        int x; cin >> x;
        int y; cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi vis(n + 1, 0);
    vector<pi> ans;
    int cnt = 0;
    f(i, 1, n + 1) {
        if(!vis[i]) {
            dfs(i, adj, vis);
            cnt++;
            if(i - 1 > 0) ans.push_back({i - 1, i});
        }
    }

    cout << cnt - 1 << nl;
    for(auto &c : ans) cout << c.first << " " << c.second << nl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--) solve();
    solve();
    return 0;
}