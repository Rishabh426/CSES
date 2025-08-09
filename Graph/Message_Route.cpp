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
        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<pi> q;
    vi par(n + 1), vis(n + 1);
    par[1] = -1;
    q.push({1, 1});
    vis[1] = 1;

    while(!q.empty()) {

        int node = q.front().first;
        int conn = q.front().second;
        q.pop();

        if(node == n) {cout << conn << nl; break;}

        for(auto &c : adj[node]) {
            if(!vis[c]) {
                vis[c] = 1;
                par[c] = node;
                q.push({c, conn + 1});
            }
        }
    }

    if(!vis[n]) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    vi ans;
    int curr = n;
    while(curr != -1) {
        ans.pb(curr);
        curr = par[curr];
    }

    reverse(all(ans));
    for(auto &c : ans) cout << c << " ";
    cout << nl;
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