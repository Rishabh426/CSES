#include <bits/stdc++.h>
using namespace std;

//////////////////////////// basic macros ///////////////////////////////////////////////////////////////
#define vi vector<int>
#define all(a) (a).begin(), (a).end() // for sorting use sort(all(myVector));
#define nl "\n"

void input(vi& arr) {
    for (auto &c : arr) cin >> c;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi arr(n);
    input(arr);
    sort(all(arr)); 

    int i=0, j=n-1, ans = 0;
    while(i<=j) {
        if(arr[i]+arr[j] <= k) i++;
        ++ans, --j;
    }

    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
