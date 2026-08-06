#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {\
        
        int sz = arr.size();
        if(sz == 1) return arr[0];
        
        int bestend = arr[0];
        int ans = arr[0];
        
        for(int i = 1; i < sz; i++){
            int sum = arr[i] + bestend;
            bestend = min(arr[i], sum);
            ans = min(bestend, ans);
        }
        return ans;
        
    }
};

// qn: https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1