#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return nums[0];

        int sum = 0;
        int maxend = 0, minend = 0;
        int maxsum = INT_MIN, minsum = INT_MAX;

        for(int x : nums){
            sum += x;
            maxend = max(x, maxend + x);
            minend = min(x, minend + x);

            maxsum = max(maxend, maxsum);
            minsum = min(minsum, minend);
        }

        if (maxsum < 0) return maxsum;      // all negative
        
        return max(maxsum, sum - minsum);
    }
};

// qn: https://leetcode.com/problems/maximum-sum-circular-subarray/?utm_source=chatgpt.com