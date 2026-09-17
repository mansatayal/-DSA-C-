#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while(start <= end){
            mid = start + ((end - start)/2);
            if(nums[mid] == target) return mid;
            (nums[mid] > target)? end = mid - 1 : start = mid + 1;
        }
        return -1;
    }
};

// qn: https://leetcode.com/problems/binary-search/