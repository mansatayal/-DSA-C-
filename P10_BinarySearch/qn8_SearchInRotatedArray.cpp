#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(high >= low){
            int mid = low + ((high - low)/2);

            if(nums[mid] == target) return mid;
            
            if(nums[low] <= nums[mid]){
                // left sort
                (nums[mid] > target && nums[low] <= target)? high = mid - 1 : low = mid + 1;
            }
            else{
                // right sort    low > mid
                (nums[mid] < target && nums[high] >= target)? low = mid + 1: high = mid - 1;
            }

        }

        return -1;
    }
};


// qn: https://leetcode.com/problems/search-in-rotated-sorted-array/description/