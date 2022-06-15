
// Submitted on Jun 15, 2022, 1:43:25 PM

#include<bits/stdc++.h>
int bs(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
            return mid;
        }
        
        else if((mid%2 != 0 && arr[mid] == arr[mid-1])  ||  (mid%2 == 0 && arr[mid] == arr[mid+1]))
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    
    return 0;
}
int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int f = bs(arr,n);
    return arr[f];
}
