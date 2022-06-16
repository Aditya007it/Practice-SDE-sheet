

class Solution {
public:
    bool iscapacity(vector<int> &weights, int days, int mid){
        int capacity = 1;
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            if(sum > mid){
                capacity++;
                sum = weights[i];
            }
            if(capacity > days) return false;
        }
        return true;
    }
    int binary_search(int l,int h,int days,vector<int>& weights){
        int low = l; int high = h;
        int res = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(iscapacity(weights,days,mid)==true){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        if(weights.size() < days) return -1;
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        return binary_search(low,high,days,weights);
    }
    
};