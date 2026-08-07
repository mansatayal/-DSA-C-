#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        if(sz == 1) return abs(nums[0]);

        int maxend = 0, minend = 0;
        int maxsum = 0, minsum = 0;

        for(int x : nums){
            maxend = max(x, maxend + x);
            minend = min(x, minend + x);

            maxsum = max(maxsum, maxend);
            minsum = min(minsum, minend);
        }

        return max(maxsum, -minsum);    // use abs only in the end midloop will disrupt the whole thing  
        // either the max would be the sum of postives or abs of min 


    
    }
};

// qn: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/