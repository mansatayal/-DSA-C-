#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        if(high == 0) return nums[0];

        while(high > low){
            int mid = low + ((high - low)/2);

            if(nums[mid] > nums[high]) low = mid + 1;
            else high = mid ;
        }

        return nums[low];
    }
};


// qn: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
