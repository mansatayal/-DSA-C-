#include <iostream>
#include <vector>
using namespace std;

// fixed
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0;
        int high = k - 1;
        int sum = 0;

        for(int i = low; i <= high; i++){
            sum += nums[i];
        }
        double avg = (double)sum / k;
        
        low++;
        high++;

        while(high < nums.size()){
            sum = sum + nums[high] - nums[low - 1];
            avg = max(avg, (double)sum/k);
            high++; low++;
        }

        return avg;
    }
};

// qn: https://leetcode.com/problems/maximum-average-subarray-i/description/