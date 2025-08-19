#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define nl "\n"
#define pi pair<int, int>
#define pl pair<long long, long long>
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

// -----------------------MAIN CODE-------------------------------

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<pl>> adj(n + 1); 

    f(i, 0, m) {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    vll dist(n + 1, 1e18);
    dist[1] = 0;

    priority_queue<pl, vector<pl>, greater<pl>> pq; 
    pq.push({0, 1});

    while (!pq.empty()) {
        ll time = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if (time > dist[node]) continue; 

        for (auto &[a, b] : adj[node]) {
            if (time + b < dist[a]) {
                dist[a] = time + b;
                pq.push({dist[a], a});
            }
        }
    }

    f(i, 1, n + 1) cout << dist[i] << " ";
    cout << nl;
    return;
}


// -----------------------CODE ENDS HERE--------------------------------------
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