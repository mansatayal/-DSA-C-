#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        
        int low = 1;
        int high = arr[sz - 1];
        
        if(k == 2)  return arr[sz - 1] - arr[0];
        
        int ans = 1;
        
        while(high >= low){
            int mid = low + ((high - low)/2);
            int cow = 1;    // first cow placed at index 0
            
            if(arr[sz - 1] - arr[0] > mid){ // start placing after checking if it's possible or not only
                int j = 0;
                for(int i = 1; i < sz; i++){
                    if(arr[i] - arr[j] >= mid){
                        cow++;
                        j = i;
                    }
                }                
            }
            
            if(cow >= k){
                ans = max(ans, mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
        
    }
};

// qn: https://www.geeksforgeeks.org/problems/aggressive-cows/1