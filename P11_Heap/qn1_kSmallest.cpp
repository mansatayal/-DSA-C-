#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue <int> pq;    // max heap
        
        // push first kth elements
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        
        
        // check the top element (it'll be the largest amongst the ones we've pushed) if the top element is smaller or equal to the arr[i] then there's no point into pushing that else we found the new smaler element 
        for(int i = k; i < arr.size(); i++){
            if(pq.top() <= arr[i]) continue;    
            else{
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
        
    }
};


// qn: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1