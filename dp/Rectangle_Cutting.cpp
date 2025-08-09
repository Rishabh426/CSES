#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define nl "\n"
#define mod 1000000007
const int MAX = 1000;

int findans(int a, int b) {
    if(b == 0) return 0;
    return (a / b + findans(b, a % b));

}
void solve() {

    int a, b;
    cin >> a >> b;

    cout << findans(a, b) - 1 << nl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
