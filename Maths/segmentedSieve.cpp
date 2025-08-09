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

const int N = 1000001;
int prime[N] ;

void input(vi& arr) {
    for(auto &c : arr) cin >> c;
}

// we will first find sqrt(R) prime numbers ;
void sieve() {

    floop(i,2,N+1) {
        prime[i] = 1;
    }

    for(int i=2; i*i<=N; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=N; j+=i) {
                prime[j]=0;
            }
        }
    }

    return ;
}

vi generatePrime(int n) {
    
    vi ds ;
    floop(i,0,N+1) {
        if(prime[i]==1) ds.push_back(i) ;
    }

    return ds;
}
void solve()
{
    int l,r;
    cin>>l>>r;
    sieve() ;

    vi primes = generatePrime(sqrt(r)) ;
    int sz = r-l+1, n=primes.size();
    

    int dummy[sz] ;
    floop(i,1,sz) {
        dummy[i]=1;
    }

    floop(i,0,n) {
        int pr=primes[i] ;
        int firstmultiple = (l/pr) * pr;
        if(firstmultiple < l) firstmultiple += pr;

        for(int j=max(i*i, firstmultiple); j<=r; j+=i) {
            dummy[j-l] = 0;
        }   
    } 
    int ans = 0;
    floop(i,l,r+1) {
        if(dummy[i-l]==1) ++ans ;
    }

    cout<<ans<<nl;

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