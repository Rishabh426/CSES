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

// -----------------------MAIN CODE-------------------------------

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    f(i, 0, n) {
        f(j, 0, m) cin >> arr[i][j];
    }

    vector<vi> monster(n, vi(m, 1e9));
    vector<vector<pi>> par(n, vector<pi>(m, {-1, -1}));
    vector<vi> vis(n, vi(m, 0));
    queue<pair<pi, int>> mq, q;         // {{row, col}, min_steps}

    f(i, 0, n) {
        f(j, 0, m){
            if(arr[i][j] == 'M') {
                mq.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            if(arr[i][j] == 'A') q.push({{i, j}, 0});
        }   
    }

    while(!mq.empty()) {

        int row = mq.front().first.first;
        int col = mq.front().first.second;
        int stp = mq.front().second;
        mq.pop();

        monster[row][col] = stp;
        f(i, 0, 4) {
            int nr = row + dx[i];
            int nc = col + dy[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && arr[nr][nc] != '#') {
                vis[nr][nc] = 1;
                monster[nr][nc] = stp + 1;
                mq.push({{nr, nc}, stp + 1});
            }
        }
    }
    
    f(i, 0, n) f(j, 0, m) vis[i][j] = 0;
    int startr = q.front().first.first;
    int startc = q.front().first.second;

    if(monster[startr][startc] <= 0) {
        cout << "NO" << nl;
        return;
    }

    vis[startr][startc] = 1;

    int row = -1, col = -1;
    while(!q.empty()) {

        int r = q.front().first.first;
        int c = q.front().first.second;
        int stp = q.front().second;
        q.pop();

        if(r == 0 || c == 0 || r == n - 1 || c == m - 1) {
            row = r;
            col = c;
            break;
        }
        if(stp >= monster[r][c]) {
            cout << "NO" << nl;
            return;
        }

        f(i, 0, 4) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && arr[nr][nc] != '#' && stp + 1 < monster[nr][nc]) {
                vis[nr][nc] = 1;
                par[nr][nc] = make_pair(r, c);
                q.push({{nr, nc}, stp + 1});
            }
        }
    }

    if(row == -1) {
        cout << "NO" << nl;
        return;
    }

    string ans = "";
    while (par[row][col].first != -1 && par[row][col].second != -1) {
        int pr = par[row][col].first;
        int pc = par[row][col].second;
        if (pr + 1 == row) ans.pb('D');
        else if (pr - 1 == row) ans.pb('U');
        else if (pc + 1 == col) ans.pb('R');
        else if (pc - 1 == col) ans.pb('L');
        row = pr;
        col = pc;
    }
    reverse(all(ans));
    cout << "YES" << nl;
    cout << ans.length() << nl;
    cout << ans << nl;
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