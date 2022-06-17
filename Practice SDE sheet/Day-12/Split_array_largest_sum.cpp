class Solution {
public:
    bool isSplit(vector<int> &arr, int m, int mid){
        int subarray=1;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum = sum+arr[i];
            if(sum > mid){
                subarray++;
                sum = arr[i];
            }
            if(subarray > m) return false;
        }
        return true;
    }
    int binary_search(int l, int h, int m, vector<int> &arr){
        int low = l; int high = h;
        int res = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isSplit(arr,m,mid)){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(),0);
        return binary_search(l,h,m,nums);
    }
};