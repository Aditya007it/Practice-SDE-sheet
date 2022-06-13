
// Submitted on Jun 13, 2022, 12:23:20 PM


int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
    int mA = arr[0];
    int mI = arr[0];
    int ans = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i] < 0){
            swap(mA, mI);
        }
        mA = max(arr[i], mA*arr[i]);
        mI = min(arr[i], mI*arr[i]);
        ans = max(mA, ans);
    }
    return ans;
}
