

// // Submitted on Jun 14, 2022, 1:06:40 PM

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unsigned int dp[n+1];
        
        memset(dp,0,sizeof(dp));
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<=i; j++){
                string str = s.substr(j, i-j+1);
                if(std::find(wordDict.begin(), wordDict.end(), str) != wordDict.end()){
                    if(j > 0){
                        dp[i] += dp[j-1];
                    }
                    else{
                        dp[i] += 1;
                    }
                }
            }
        }
        for(int i=0; i<n ; i++){
            cout<<dp[i]<<" ";
        }
        return dp[n-1]>0;
        
    }
};