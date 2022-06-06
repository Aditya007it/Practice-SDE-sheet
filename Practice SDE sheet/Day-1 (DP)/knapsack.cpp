// Accepted on CodeStudio
// Date = 6th June 2022 (11:30 AM)....

int knapsack(vector<int> &values, vector<int> &weights, int n, int C,  vector<vector<int>> &dp)
{
    if(n == 0 || C == 0){
        return 0;
    }
    if(dp[n][C]!=-1){
        return dp[n][C];
    }
    if(weights[n-1] <= C){
        return dp[n][C] = max(values[n-1] + knapsack(values,weights,n-1,C-                weights[n-1],dp), knapsack(values,weights,n-1,C,dp));
    }
    else{
          return dp[n][C] = knapsack(values,weights,n-1,C,dp);   
    }
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n+1, vector<int>(w+1,-1));
    return knapsack(values,weights,n,w,dp);
}

