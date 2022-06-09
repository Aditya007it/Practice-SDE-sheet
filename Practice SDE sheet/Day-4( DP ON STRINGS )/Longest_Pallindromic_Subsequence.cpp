// Accepted on codestudio..
// Submitted on Jun 9, 2022, 12:48:26 PM

#include<bits/stdc++.h>
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    
    string b = s;
    reverse(b.begin(), b.end());
    string a = s;
    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}