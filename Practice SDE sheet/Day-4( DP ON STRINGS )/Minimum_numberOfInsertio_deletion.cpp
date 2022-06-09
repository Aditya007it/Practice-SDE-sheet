

// Accepted on codestudio..
// Submitted on Jun 9, 2022, 12:47:32 PM


int LCS(string a,string b, int n, int m){
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

int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();
    int var = LCS(str,ptr,n,m);
    return (m+n) - 2*var;
}