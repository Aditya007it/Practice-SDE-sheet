
// Accepted on codestudio..
// on 8 june 2022 (1.30 PM)

#include<bits/stdc++.h>
int LCS(string s, string t, int n, int m, vector<vector<int>> &dp){
    if(n==0 || m==0){
        return 0;
    }
    else if(dp[n][m]!=-1){
        return dp[n][m];
    }
    else if(s[n-1] == t[m-1]){
        return dp[n][m] = 1 + LCS(s,t,n-1,m-1,dp);
    }
    else{
        return dp[n][m] = max(LCS(s,t,n-1,m,dp),LCS(s,t,n,m-1,dp));
    }
}

int lcs(string s, string t)
{
	//Write your code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    return LCS(s,t,n,m,dp);
}