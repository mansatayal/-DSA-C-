#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map <int,int> m;
        m[0]++;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = sum % k;      // sum = 5x + y  this y is the remainder we're looking for
            if(rem < 0) rem = rem + k;   //negative signs can't be handled by modulo correctly
            ans += m[rem];
            m[rem]++;        // add in hashmap to track the count of remainders  
        }
        return ans;
    }

    // Note: -9 % 5 => -4 using the c++ modulo but in reality it's 1 
    // -9 % 5 => 9 % 5 => 4(-1) + 5 = -1
    // or 9 % 5 = 4 as 9 - 5 = 4 similarly -9 % 5 = 1 as -9 - (-10) = 1
};

// qn: https://leetcode.com/problems/subarray-sums-divisible-by-k/