// Submitted on Jun 11, 2022, 11:18:59 AM

#include<bits/stdc++.h>

bool isPallindrome(int start, int end, string s){
    while(start < end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}
int solve(int i, int j, string str, vector<vector<int>> &dp){
    if(i >= j){
        return 0;
    }
    if(isPallindrome(i,j,str)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    int left,right;
    for(int k=i; k<=j-1; k++){
        if(isPallindrome(i,k,str)){
            if(dp[i][k]!=-1){
                left = dp[i][k];
            }
            else{
                left = solve(i,k,str,dp);
                dp[i][k] = left;
            }
            if(dp[k+1][j]!=-1){
                right = dp[k+1][j];
            }
            else{
                right = solve(k+1,j,str,dp);
                dp[k+1][j] = right;
            }
            int temp = 1 + left + right;
            ans = min(ans,temp);
        }
    }
    return dp[i][j] = ans;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(0,str.size()-1, str, dp);
}
