#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7 ;
long expoRec(int a, int b) {
    if (b == 0) return 1; 
    long res = expoRec(a, b / 2);    
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
        int a,b;
        cin>>a>>b;
        cout<<expoRec(a,b)<<"\n" ;
    }
}
