
// Submitted on Jun 9, 2022, 2:00:32 PM

int lcs(string &A, string &B,string &C, int n, int m, int p){
    int dp[n+1][m+1][p+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            for(int k=0; k < p+1; k++){
                if(i==0 || j==0 || k==0){
                    dp[i][j][k] = 0;
                }
                
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            for(int k=1; k < p+1; k++){
                if(A[i-1]==B[j-1] && B[j-1]==C[k-1]){
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }
                else{
                     dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]),dp[i][j][k-1]);
                }
                
            }
        }
    }
    
    return dp[n][m][p];
}


int LCS(string A, string B, string C, int n, int m, int k)
{
	// Write your code here.
    return lcs(A,B,C,n,m,k);
}