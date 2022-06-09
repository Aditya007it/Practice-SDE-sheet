
// Submitted on Jun 9, 2022, 2:08:32 PM

#include<bits/stdc++.h>
int LCS(string s, string t, int n, int m, vector<vector<int>> &dp){
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int minInsertion(string &str)
{
    // Write your code here.
    string b = str;
    reverse(b.begin(), b.end());
    string a = str;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    return m - LCS(a,b,n,m,dp);
    
}