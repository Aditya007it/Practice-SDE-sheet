

// Submitted on Jun 15, 2022, 1:25:23 PM

int bs(int *arr, int n){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
            return mid;
        }
        else if(arr[low] <= arr[mid] && arr[mid] <= arr[high]){
            return low;
        }
        else if(arr[mid] >= arr[low])
        {
            low = mid+1;
        }
        else if(arr[mid] <= arr[high]){
            high = mid-1;
        }
    }
    
    return 0;
}

int binary_search(int *arr, int low, int high, int key){
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int search(int* arr, int n, int key) {
    // Write your code here.
    int minimum_index = bs(arr,n);
    if(arr[minimum_index] == key) return minimum_index;
    int b1 = binary_search(arr,0,minimum_index-1,key);
    int b2 = binary_search(arr,minimum_index,n-1,key);
    if(b1 == -1 && b2 == -1) return -1;
    else{
        if(b1 == -1){
            return b2;
        }
        else{
            return b1;
        }
    }
}