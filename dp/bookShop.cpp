#include <bits/stdc++.h>
using namespace std;

//////////////////////////// basic macros ///////////////////////////////////////////////////////////////

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define nl "\n"
#define pi pair<int, int>
#define pl pair<long long, long long>
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb(a) push_back(a)
#define pp() pop_back()
#define floop(i, start, end) for (int i = start; i < end; ++i)
#define fnloop(i, start, end) for (int i = start; i >= end; --i)

void solve()
{
    int n,x;
    cin >> n >> x;

    vi arr(n, 0), brr(n, 0);
    floop(i, 0, n) cin >> arr[i];
    floop(i, 0, n) cin >> brr[i];

    vector<vi> dp(n + 1, vi(x + 1, 0));

    floop(i, 1, n+1) {
        int price = arr[i - 1];
        int pages = brr[i - 1];
        floop(j, 0, x + 1) {
            int take = (j >= price ? dp[i - 1][j - price] + pages : 0);
            int skip = dp[i - 1][j];
            dp[i][j] = max(skip, take);
        }
    }

    cout << dp[n][x] << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // t--;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}