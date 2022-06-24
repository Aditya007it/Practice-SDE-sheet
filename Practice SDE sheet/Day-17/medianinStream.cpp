#include<bits/stdc++.h>

void insert(int x,priority_queue <int, vector<int>, greater<int>> &minheap, priority_queue <int, vector<int>> &maxheap){
    if(maxheap.size() == minheap.size()){
        if(maxheap.size() == 0){
            maxheap.push(x);
            return;
        } 
        else if(x < maxheap.top()){
            maxheap.push(x);
        }
        else{
            minheap.push(x);
        }
    }
    else{
        // size of maxheap > size of minheap
        // size of min heap > size of maxheap
        if(maxheap.size() > minheap.size()){
            if(x >= maxheap.top()){
                minheap.push(x);
            }
            else{
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
                maxheap.push(x);
            }
            
        }
        else{
            
            if(x <= minheap.top()){
                maxheap.push(x);
            }
            else{
                int temp = minheap.top();
                minheap.pop();
                maxheap.push(temp);
                minheap.push(x);
            }
        }
    }
}

int findmedain(priority_queue <int, vector<int>, greater<int>> &minheap, priority_queue <int, vector<int>> &maxheap){
    if(minheap.size() == maxheap.size()){
        return (maxheap.top() + minheap.top())/2;
    }
    else if(minheap.size() < maxheap.size()){
        return maxheap.top();
    }
    else{
        return minheap.top();
    }
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here
    vector<int> ans;
    priority_queue<int,vector<int>> maxheap;
    priority_queue <int, vector<int>, greater<int>> minheap;
    int i=0;
    while(i<n){ 
        insert(arr[i],minheap,maxheap);
        ans.push_back(findmedain(minheap,maxheap));
        i++;
    }
  
    return ans;
}
