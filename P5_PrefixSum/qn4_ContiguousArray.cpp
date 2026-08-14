#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0, one = 0;
        int ans = 0;
        unordered_map<int,int> m;
        // m[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zero++;
            else one++;

            int diff = zero - one;

            if(diff == 0) {             // edge case 
                ans = max(ans, i + 1);
            }
            else{

                if(m.find(diff) == m.end()) m[diff] = i;    // track only if it's not been trackked before [bacause we want to maximize the length]

                else{
                    ans = max(ans,i - m[diff]);      //if same diff has occurred twice then the in between those two diff is all zero  
                }     
            } 
        }

        return ans;
    }
};

// qn: https://leetcode.com/problems/contiguous-array/