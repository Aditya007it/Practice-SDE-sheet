

// Submitted on Jun 16, 2022, 1:52:27 PM

#include<bits/stdc++.h>
bool isallocateTime(vector<int> time, int n, int k, long long int mid){
    int day = 1;
    long long int sum = 0;
    for(int i=0; i<n; i++){
        sum += time[i];
        if(sum > mid){
            day++;
            sum = time[i];
        }
        if(day > k) return false;
    
    }
    return true;
    
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long low =  *max_element(time.begin(), time.end());
    long long summ = 0;
    long long high = accumulate(time.begin(), time.end(), summ);
    long long res = -1;
//     if(n > m) return res;
    while(low <= high){
        long long int mid = low + (high-low)/2;
        if(isallocateTime(time, m, n, mid)){
            res = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    
    return res;
}

