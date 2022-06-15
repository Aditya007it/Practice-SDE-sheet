
// Submitted on Jun 15, 2022, 12:31:46 PM

int fun(int arr[], int n){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
            return mid;
        }
        else if(arr[low] <= arr[mid] && arr[mid] <= arr[high]){
            return low;
        }
        else if(arr[mid] >= arr[low]){
            low = mid+1;
        }
        else if(arr[mid] <= arr[high]){
            high = mid-1;
        }
    }
    return 0;
    
}
int rotatedArray(int arr[], int n)
{
    // Write your code here.
    return arr[fun(arr,n)];
    
}