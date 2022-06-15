
// Submitted on Jun 15, 2022, 2:24:52 PM

int ceilingInSortedArray(int n, int x, vector<int> &arr){
    // Write your code here.
    int low = 0;
    int high = n-1;
    int res = -1;
    while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] >= x){
                if(arr[mid]==x){
                    return arr[mid];
                }
                res = mid;
                high = mid-1;
                
            }
            else if(arr[mid] < x){
                low = mid+1;
            }
        }
       return arr[res];
    
}
