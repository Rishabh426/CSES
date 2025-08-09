#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long
    #define vi vector<int>
    #define vii vector<vector<int>>
    #define nl "\n"
    const int mod = 1e9 + 7;
    const static int MAX = 200;
    bool dp[MAX + 1][MAX + 1];
public:
    bool findans(vi &arr, int n, int s) {
    
        if(n == 0) return true;
        if(n < 0) return false;
        if(dp[n][s] != false) return dp[n][s];

        bool nt = findans(arr, n - 1, s);
        bool t = findans(arr, n - 1, s - arr[n]);

        return dp[nt][t] = nt || t;
    }
    bool canPartition(vi& nums) {
        
        int n = nums.size();
        memset(dp, false, sizeof(dp));

        int mx = accumulate(begin(nums), end(nums), 0);
        if(mx & 1) return false;

        return findans(nums, n - 1, mx / 2);
    }
};

