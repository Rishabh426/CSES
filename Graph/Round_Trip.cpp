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

// varible used in problem
// -------------------------
int x = -1;
int y = -1;
// -------------------------

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

bool dfs(vector<vi>& adj, vi& vis, vi& par, int node, int parent) {

    vis[node] = 1;
    for(auto &c : adj[node]) {
        if(parent == c) continue;
        else if(!vis[c]) {
            par[c] = node;
            if(dfs(adj, vis, par, c, node) == true) return true;
        }
        else {
            x = c;
            y = node;
            return 1;
        }
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n + 1);
    f(i, 0, m) {
        int a; cin >> a;
        int b; cin >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi par(n + 1), vis(n + 1, 0);
    f(i, 1, n + 1) {
        if(!vis[i]) {
            if(dfs(adj, vis, par, i, -1)) break;
        }
    }

    if(x == -1) cout << "IMPOSSIBLE" << nl;
    else {
        vi ans;
        ans.pb(x);
        int curr = y;
        while(curr != x) {
            ans.pb(curr);
            curr = par[curr];
        }
        ans.pb(x);
        cout << ans.size() << nl;
        for(auto &c : ans) cout << c << " ";
        cout << nl;
    }

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