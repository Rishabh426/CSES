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

void solve()
{
    int n, m;
    cin >> n >> m;

    pi A = {-1, -1}, B = {-1, -1};
    vector<vector<char>> adj(n, vector<char>(m, 0));
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'A')
                A = {i, j};
            if (adj[i][j] == 'B')
                B = {i, j};
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> moveDir(n, vector<char>(m, 0));

    q.push(A);
    vis[A.first][A.second] = 1;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    char dirChar[] = {'U', 'R', 'D', 'L'};

    int found = false;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        if (make_pair(r, c) == B) {
            found = true;
            break;
        }
            
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] && (adj[nr][nc] == '.' || adj[nr][nc] == 'B'))
            {
                vis[nr][nc] = 1;
                q.push({nr, nc});
                parent[nr][nc] = {r, c};
                moveDir[nr][nc] = dirChar[i];
            }
        }
    }

    if(!found) {cout << "NO" << nl; return;}
    string ans = "";
    int r = B.first, c = B.second;
    while (make_pair(r, c) != A)
    {
        ans.push_back(moveDir[r][c]);
        tie(r, c) = parent[r][c];
    }
    cout << "YES" << nl;
    cout << ans.length() << nl;
    reverse(ans.begin(), ans.end());
    cout << ans << nl;
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