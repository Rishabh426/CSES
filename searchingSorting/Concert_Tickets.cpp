#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define vi vector<int>
#define floop(i, start, end) for (int i = start; i < end; ++i)

void solve() {
    int n, m;
    cin >> n >> m;

    vi arr(n), brr(m);
    for (auto &x : arr) cin >> x;
    for (auto &x : brr) cin >> x;

    sort(arr.begin(), arr.end());

    for (int price : brr) {
        auto it = upper_bound(arr.begin(), arr.end(), price);
        if (it == arr.begin()) {
            cout << -1 << nl;
        } else {
            --it;
            cout << *it << nl;
            arr.erase(it); 
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}