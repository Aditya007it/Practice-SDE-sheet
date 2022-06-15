
// submitted on 2022-06-15 10:56:05

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int binary_search1(vector<int> &arr, int x)
    {
        int res = -1;
        int low = 0;
        int high = arr.size()-1;
        
        while(low<=high)
        {
            int mid = (high+low)/2;
            if(arr[mid]==x)
            {
                res = mid;
                low = mid+1;
            }
            else if(arr[mid] > x)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return res;
    }
    
    int binary_search2(vector<int> &arr, int x)
    {
        int res = -1;
        int low = 0;
        int high = arr.size()-1;
        
        while(low<=high)
        {
            int mid = (high+low)/2;
            if(arr[mid]==x)
            {
                res = mid;
                high = mid-1;
            }
            else if(arr[mid] > x)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return res;
    }
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int m1 = binary_search1(arr,x);
        int m2 = binary_search2(arr,x);
        vector<int> ans;
        if(m1==-1 || m2==-1)
        {
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(m2)
        ;
        ans.push_back(m1);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends