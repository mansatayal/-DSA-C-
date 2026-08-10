#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        int sum = 0;
        int prefix = 0;
        int suffix = 0;

        for(int i = 0; i < sz; i++){
            sum += nums[i];
        }

        for(int i = 0; i < sz; i++){
            // prefix in start is 0 so it checks is the pivot is at 0 or not
            suffix = sum - prefix - nums[i];    // sum = prefix + suffix + nums[i]

            if(prefix == suffix){
                return i;
            }

            prefix += nums[i];      // this adds nums[i] for index 1 for i = 0 
        }
        
        return -1;
    }
};

// prefix: if i = 2 then sum of a[0] + a[1]
// suffix: if sz = 7 & i = 5 them sum of a[6] + a[7]

// qn: https://leetcode.com/problems/find-pivot-index/description/