#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());


        for(int i = 0; i < sz; i++){
            // avoid repetition
            if(i > 0 and nums[i] == nums[i-1]){
                    continue;
            }
            int target = nums[i] * - 1;     //nums[i] + left + right == 0 ==> -nums[i] =left + right 
            int left = i + 1;
            int right = sz - 1;

            while(right > left){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    sol.push_back({nums[i],nums[left], nums[right]});
                    left++; right--;

                    // to avoid repetition of the elements
                    while(right > left and nums[left] == nums[left - 1]){
                        left++;
                    }
                    while(right > left and nums[right] == nums[right +1]){
                        right--;
                    }
                }
                else if(sum > target){
                    right--;
                }
                else{                       // sum < target
                    left++;
                }
                
            }
        }

        return sol;
    }
};



/*QUESTION: 3Sum
link: https://leetcode.com/problems/3sum/description/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105


*/