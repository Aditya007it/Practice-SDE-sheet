

// Submitted on Jun 15, 2022, 11:12:01 AM

int binary_search_1(int arr[], int n, int x){
    int low = 0; int high = n-1;
    int res = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            res = mid;
            high = mid - 1;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return res;
}

int binary_search_2(int arr[], int n, int x){
    int low = 0; int high = n-1;
    int res = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            res = mid;
            low = mid+1;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return res;
}

int countOccurences(int arr[], int n, int X)
{
	//Write your code here
    int m1 = binary_search_1(arr,n,X);
    int m2 = binary_search_2(arr,n,X);
    if(m1 == -1 && m2 == -1) return 0;
    return (m2-m1+1);
}