#include <iostream>
#include <vector>
using namespace std;

// dynamic
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int low = 0;
        int count = 0;

        for(int high = 0; high < nums.size(); high++){
            if(nums[high] == 0){
                zero++;
                while(zero > k){

                    // decrement 0 if low is 0
                    if(nums[low] == 0){
                        zero--;
                    }

                    low++;
                }
            }
            count = max(count,(high - low + 1));

        }
        return count;
    }
};

/* Question: Max Consecutive Ones III
link: https://leetcode.com/problems/max-consecutive-ones-iii/description/

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/