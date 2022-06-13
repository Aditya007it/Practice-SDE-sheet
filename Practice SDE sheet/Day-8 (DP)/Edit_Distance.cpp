
// Submitted on Jun 13, 2022, 11:44:07 AM

int fun(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            dp[i][0] = i;
            dp[0][j] = j;
        } 
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                int insertion = 1 + dp[i][j-1];
                int deletion = 1 + dp[i-1][j];
                int replace = 1 + dp[i-1][j-1];
                dp[i][j] = min(insertion, min(deletion, replace));
            }
        } 
    }
    return dp[n][m];
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    return fun(str1, str2,n, m);
}