
// Accepted on Codestudios..
// On- 7th June 2022 (12:50 PM)
int m = 1000000007;
int count_subsetSum(int n, int sum, vector<int> &arr){
    int dp[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]]%m + dp[i-1][j]%m;
            }
            else{
                dp[i][j] = dp[i-1][j]%m;
            }
        }
    }
    
    return dp[n][sum]%m;
}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int sumofArray = 0;
    for(int i=0; i<n; i++)
    {
        sumofArray += arr[i];
    }
    int sumS1 = (target + sumofArray)/2;
    if(sumofArray+target < 0 || (sumofArray+target)%2!=0) return 0;
    return count_subsetSum(n,sumS1,arr);
}
