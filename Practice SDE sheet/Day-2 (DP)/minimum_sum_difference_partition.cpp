// Accepted on Codestudios..
// On- 7th June 2022 (11:52 AM)


#include <climits>
vector<int> subsetSum(vector<int>& arr, int n, int sum){
    bool dp[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0;j<sum+1; j++){
            if(i==0) dp[i][j] = false;
            if(j==0) dp[i][j] = true;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1;j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> ans;
    for(int i=0; i<=sum/2; i++){
        if(dp[n][i]==true){
            ans.push_back(i);
        }
    }
    return ans;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int range = 0;
    for(int i=0; i<n; i++){
        range = range + arr[i];
    }
    vector<int> ans = subsetSum(arr,n,range);
    int res = INT_MAX;
    for(int i=0; i<ans.size(); i++){
        res = min(res,range-2*ans[i]);
    }
    return res;
}
