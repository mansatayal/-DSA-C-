#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return nums[0];

        int maxend = nums[0];
        int minend = nums[0];       // as negative * negative results in positive 
        int ans = nums[0];

        for(int i = 1; i < sz; i++){
            int pmax = nums[i] * maxend;
            int pmin = nums[i] * minend;

            maxend = max({nums[i], pmax, pmin});
            minend = min({nums[i], pmax, pmin});

            ans = max({ans, maxend, minend});
        }

        return ans;
    }
};

//qn: https://leetcode.com/problems/maximum-product-subarray/?utm_source=chatgpt.com