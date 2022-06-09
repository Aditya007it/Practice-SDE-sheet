

// Accepted on codestudio..
// Submitted on Jun 9, 2022, 11:48:41 AM

#include<bits/stdc++.h>
string shortestSupersequence(string a, string b)
{
	// Write your code here.
    string ans;
    int i,j,m,n;
    i = n = a.size();
    j = m = b.size();
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
    
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j] < dp[i][j-1]){
            ans.push_back(b[j-1]);
            j--;
        }
        else{
            ans.push_back(a[i-1]);
            i--;
        }
    }
    while(i > 0){
        ans.push_back(a[i-1]);
         i--;
    }
    while(j > 0){
        ans.push_back(b[j-1]);
         j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}