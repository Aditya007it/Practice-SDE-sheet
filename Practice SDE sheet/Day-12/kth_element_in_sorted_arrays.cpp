

// Submitted on Jun 17, 2022, 12:34:32 PM

#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int n1 = m;
    int n2 = n;
    if(n1 >  n2) return ninjaAndLadoos(row2,row1,n2,n1,k);
    int low = max(0, k-n2);
    int high = min(n1,k);
    
    while(low <= high){
        int cut1 = low + (high-low)/2;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : row1[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN : row2[cut2-1];
        int r1 = cut1 == n1 ? INT_MAX : row1[cut1];
        int r2 = cut2 == n2 ? INT_MAX : row2[cut2];
        
        if(l1 <= r2 && l2 <= r1) return max(l1,l2);
        else if(l1 > r2){
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
    }
    return 0;
}