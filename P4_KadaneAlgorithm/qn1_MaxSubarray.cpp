#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return nums[0];

        int bestend = nums[0];
        int ans = nums[0];

        for(int i = 1; i < sz; i++){
            int sum = bestend + nums[i];    // sum of the subarray + current elemnt
            bestend = max(nums[i], sum);    // sum is greater or the current element 
            ans = max(bestend, ans);        // greatest subarray so far

        }

        return ans;
    }
};

// qn: https://leetcode.com/problems/maximum-subarray/description/?utm_source=chatgpt.com