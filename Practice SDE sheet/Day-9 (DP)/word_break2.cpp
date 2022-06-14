

// Submitted on Jun 14, 2022, 3:04:20 PM

#include <bits/stdc++.h>
void solve(string s, set<string> &st, int index, vector<string> &ans, string ds ){
        if(index >= s.size()){
            ds.pop_back();
            ans.push_back(ds);
            return;
        }
        
        string temp ;
        for(int i=index; i<s.size(); i++){
            temp += s[i]; 
            if(st.count(temp) == 1){
                solve(s,st,i+1,ans,ds + temp + " ");
            }
        }
    }

vector<string> getAllValidSentences(string &sentence, vector<string> &dictionary)
{
    //  write your code here.
        vector<string> ans;
        string ds;
        set<string> st;
        for(auto &it : dictionary){
            st.insert(it);
        }
        solve(sentence,st,0,ans,ds);
        return ans;
}