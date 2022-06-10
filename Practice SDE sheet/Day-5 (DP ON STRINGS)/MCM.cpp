// Submitted on Jun 10, 2022, 7:37:53 PM


#include<bits/stdc++.h>
int dp[102][102];
int mcm(vector<int> &arr, int i, int j){
    if(i >= j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int cost = arr[i-1]*arr[k]*arr[j];
        int temp = mcm(arr,i,k) + mcm(arr,k+1,j) + cost;
        ans = min(ans,temp);
    }
    return dp[i][j] = ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    memset(dp,-1,sizeof(dp));
    return mcm(arr,1,N-1);
    
}