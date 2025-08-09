#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const int MOD = 1e9+7 ;
const int pimod = 1e9+6 ;

ll expoIter(ll a, ll b, int mod) {

    int ans = 1;
    while(b) {
        if(b&1) ans = (ans*a) % mod;

        a = (a*a)%mod;
        b>>=1;
    }

    return ans ;
    
}
ll expoRec(ll a, ll b) {
    if (b == 0) return 1; 
    ll res = expoRec(a, b / 2);    
    res = (res * res) % MOD; 
    
    if (b & 1) 
        return (a * res) % MOD; 
    else 
        return res; 
}

int main() {
    
    int t;
    cin>>t;

    while(t--) {
        long long a,b,c;
        cin>>a>>b>>c;
        b=expoIter(b,c,pimod);
        cout<<expoIter(a,b,MOD)<<"\n";
    }
}
