


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size()-1;
        int res = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(letters[mid] == target || letters[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
                res = mid;
            }
        }
        return letters[res];
        
    }
};