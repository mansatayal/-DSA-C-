#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        vector <int> ans(sz,-1);
        stack <int> temp;

        for(int i = sz * 2 - 1; i >= 0; i--){   // go twice through the array as it's circular
            int idx = i % sz;       // wrap i back into the corerct range
            
            // pop till either the stack is empty or a greater element is found
            while(!temp.empty() && nums[idx] >= temp.top()) temp.pop();

            if(sz > i){
                ans[idx] = temp.empty()? -1 : temp.top();   // store 
            }

            temp.push(nums[idx]);   // push the current 
        }

        return ans;

        // Loop through the array twice to handle the circular wraparound.
        // First lap (i >= sz): just fills the stack, no answers recorded yet.
        // Second lap (i < sz): stack now has wraparound info, so answers get recorded.
        // e.g. [5,4,3,2,1] -> index 1 (val 4) needs to find 5 at index 0,
        // which only works because index 0 already got pushed during the first lap.  
    }
};

// qn: https://leetcode.com/problems/next-greater-element-ii/