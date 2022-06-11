
// Submitted on Jun 11, 2022, 2:03:22 PM

#include<bits/stdc++.h>
int mod = 1000000007;
#define ll long long 
int solve(string &s, int i, int j, bool istrue, vector<vector<vector<ll>>> &dp){
    if(i>j) return 0;
    if(i == j){
        if(istrue){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }
    if(dp[i][j][istrue]!= -1) return dp[i][j][istrue];
    ll ans = 0;
    for(int k=i+1; k<=j-1; k+=2){
        ll lt = solve(s,i,k-1,true,dp);
        ll lf = solve(s,i,k-1,false,dp);
        ll rt = solve(s,k+1,j,true,dp); 
        ll rf = solve(s,k+1,j,false,dp);
        if(s[k] == '&'){
            if(istrue == true){
                ans = (ans + (lt*rt)%mod)%mod;
            }else{
                ans = (ans + ((lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod))%mod;
            }
        }
        else if(s[k] == '|'){
            if(istrue == true){
                ans = (ans + ((lt*rt)%mod + (lf*rt)%mod + (lt*rf)%mod))%mod;
            }else{
                ans = (ans + (lf*rf)%mod)%mod;
            }
        }
        else{
            if(istrue == true){
                ans = (ans + ((lt*rf)%mod + (lf*rt)%mod))%mod;
            }else{
                ans = (ans + ((lt*rt)%mod + (lf*rf)%mod))%mod;
            }
        }
    }
    return dp[i][j][istrue] = ans;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1,vector<ll>(2, -1)));
    return solve(exp,0,exp.size()-1,true,dp);
}