//ACCEPTED ON 9TH JUNE 2022...
// ON - 10.44aAM


int lcs(string &str1, string &str2){
	//	Write your code here.
    int n = str1.size();
    int m = str2.size();
    int dp[n+1][m+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    int res = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(str1[i-1] == str2[j-1] ){
                dp[i][j] = 1 + dp[i-1][j-1];
                res = max(res,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    
    return res;
}