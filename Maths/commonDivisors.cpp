#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define nl "\n"

void input(vi& arr) {
    for (auto &c : arr) cin >> c;
}

void solve() {
    int n;
    cin >> n;

    vi arr(n);
    input(arr);

    int maxElem = *max_element(arr.begin(), arr.end());

    vector<int> freq(maxElem + 1, 0);

    for (int x : arr) {
        freq[x]++;
    }

    for (int g = maxElem; g >= 1; --g) {
        int count = 0;

        for (int multiple = g; multiple <= maxElem; multiple += g) {
            count += freq[multiple];
            if (count >= 2) {
                cout << g << nl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
