#include <iostream>
#include <unordered_map>
#include <vector> 
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        int sum = 0;
        m[0] = 1;           // empty
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int ques = sum - k;     // how many time sum - k was equal to the stored value
            int freq = m[ques];     
            ans += freq;
            m[sum]++;
        }
        return ans;
    }
};


// qn: https://leetcode.com/problems/subarray-sum-equals-k/

/*

The trick: instead of asking "does this specific stretch of the array add up to k," ask "if I look at everything from the very start up to right now, how much does it add up to — and have I seen that exact total, minus k, at some earlier point?"

Why that works: if two points in the array have running totals that differ by exactly k, everything between those two points must add up to exactly k. So you don't need to check every stretch one by one — you just walk through once, keep a running total, and at each step ask "have I seen (my current total − k) before?" If yes, that's a valid stretch.

The hashmap is just a memory of "which running totals have shown up so far, and how many times" — so that lookup is instant instead of having to scan backward every time.

*/