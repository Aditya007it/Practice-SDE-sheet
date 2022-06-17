 // Submitted on Jun 17, 2022, 1:04:05 PM

 int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    int count = 0;
    for(int i=0; i<n-m+1; i++){
        string str = s.substr(i,m);
        if(str == p){
            count++;
        }
    }
    
    return count;
}