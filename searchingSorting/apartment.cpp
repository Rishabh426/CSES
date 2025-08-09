#include <bits/stdc++.h>
using namespace std;
 
//////////////////////////// basic template /////////////////////////////////////////////////////////////
 
// template<typename A, typename B>
// ostream& operator<<(ostream &os, const pair<A, B> &p) {
//     return os << '(' << p.first << ", " << p.second << ')';
// }
 
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
// ostream& operator<<(ostream &os, const T_container &v) {
//     os << '{';
//     string sep;
//     for (const T &x : v)
//         os << sep << x, sep = ", ";
//     return os << '}';
// }
 
//////////////////////////// basic macros ///////////////////////////////////////////////////////////////
 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define nl "\n" 
#define pi pair<int, int>
#define pl pair<long long, long long>
#define sz(x) ((int)x.size())         // sz(vector) will give vector size
#define all(a) (a).begin(), (a).end() // for sorting use sort(all(myVector));
#define floop(i, start, end) for (int i = start; i < end; ++i)
#define fnloop(i, start, end) for (int i = start; i >= end; --i)
 
void input(vi& arr) {
    for(auto &c : arr) cin >> c;
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k ;

    vi arr(n), brr(m);
    input(arr) ; input(brr) ;

    sort(all(brr)) ; sort(all(arr)) ;
    int ans = 0;

    int i=0, j=0;
    while(i<n && j<m) {
        if(abs(arr[i]-brr[j]) <= k) ans++, i++, j++;
        else if(arr[i]-k > brr[j]) j++;
        else i++;
    }

    cout << ans << nl ;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}