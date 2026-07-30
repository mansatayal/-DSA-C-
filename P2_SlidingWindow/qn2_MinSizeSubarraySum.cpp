#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// dynamic sliding window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = 0;
        int sum = 0;
        int count = INT_MAX;

        while(high < nums.size()){
            // add to sum till we reach target
            sum += nums[high];
 
            while(sum >= target){
                int len = high - low + 1;
                count = min(len, count);    //store latest min

                // when we reach target start subtractiong from start
                sum -= nums[low];
                low++;
            }

            high++;     //add next 
        }
        

        if(count == INT_MAX){
            return 0;   // no subarray found return 0 
        }
        else{
            return count;
        }
    }
};

/* Question: Minimum Size Subarray Sum
link: https://leetcode.com/problems/minimum-size-subarray-sum/description/

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/