


//  Submitted on Jun 15, 2022, 2:28:43 PM


int floorSearch(vector<int> & v, int x, int n)
{
    // Write your code here
        int low = 0;
        int high = n-1;
        int res = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(v[mid] <= x){
                if(v[mid]==x){
                    return v[mid];
                }
                res = mid;
                low = mid+1;
                
            }
            else if(v[mid] > x){
                high = mid-1;
            }
        }
        if(res == -1) return res;
        return v[res];
}