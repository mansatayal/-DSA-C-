#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int>> ans;

        for(int l = 0; l < sz; l++){
            if(l > 0 and nums[l] == nums[l - 1]){
                continue;
            }
            int i = l+1;
            for(int i = l+1; i < sz; i++){
                if(i > l+1 and nums[i] == nums[i - 1]){
                    continue;
                }
                int j = i+1;
                int k = sz - 1;

                // nums[l] + nums[i] + c + d == target ==> c+d == target - nums[l] - nums[i]
                long long pos = (long long)target - nums[l] - nums[i];   
                while(k > j){
                    long long sum = (long long)nums[k] + nums[j];

                    if(sum == pos){
                        // check distict
                        // store
                        ans.push_back({nums[l], nums[i], nums[j], nums[k]});
                        j++; k--;

                        while(j < k and nums[j] == nums[j-1]){
                            j++;
                        }
                        while(j < k and nums[k] == nums[k+1]){
                            k--;
                        }
                    }
                    else if(sum > pos){
                        k--;
                    }
                    else{   // sum < pos
                        j++;
                    }
                }
            }
        }

        return ans;
            
    }
};


/*Question : 4Sum
link: https://leetcode.com/problems/4sum/description/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order. 

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109


*/