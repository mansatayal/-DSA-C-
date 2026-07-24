#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int diff = INT_MAX;
        int ans = 0;

        int sz = nums.size();
        
        for(int i = 0; i < sz; i++){
            int k = sz - 1;
            int j = i+1;

            while(k > j){
                int sum = nums[k] + nums[j];
                int pos = target - nums[i];      // nums[i] +  a + b == target ==> a + b = target - nums[i]

                if(sum == pos){
                    return nums[i] + nums[j] + nums[k];    // no closest required
                }
                else if(sum < pos){
                    if(diff > pos - sum){
                        diff = pos - sum;
                        ans = nums[i] + nums[j] + nums[k];
                    }
                    j++;
                }
                else{                                       // sum > pos
                    if(diff > sum - pos){
                        diff = sum - pos;
                        ans = nums[i] + nums[j] + nums[k];
                    }
                    k--;
                }
            }
        }
        return ans;

        
    }
};

/* QUESTION: 3Sum Closest
link : https://leetcode.com/problems/3sum-closest/description/

Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104



*/