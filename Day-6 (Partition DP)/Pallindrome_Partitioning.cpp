
// Submitted on Jun 11, 2022, 10:19:55 AM

bool isPallindrome(int start, int end, string &s){
    while(start < end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}
void fun(vector<vector<string>> &ans, string s, int index, vector<string> &ds){
    if(index == s.size()){
        ans.push_back(ds);
    }
    for(int i=index; i<s.size(); i++){
        if(isPallindrome(index,i,s)){
            ds.push_back(s.substr(index, i-index+1));
            fun(ans,s,i+1,ds);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<string> ds;
    vector<vector<string>> ans;
    fun(ans,s,0,ds);
    return ans;
}