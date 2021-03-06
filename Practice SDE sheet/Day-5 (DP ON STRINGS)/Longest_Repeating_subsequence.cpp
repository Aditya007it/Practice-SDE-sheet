
// Submitted on Jun 10, 2022, 10:39:14 AM

int longestRepeatingSubsequence(string st, int n)
{
	// Write your code here
    int dp[n+1][n+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(st[i-1] == st[j-1] && i!=j){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

