#include <iostream>
#include <vector>
using namespace std;


// fast and slow on array:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while(true){
            // similar to creating a linked list out of array
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow == fast){       //cycle found
                // now find the first element of the cycle
                slow = 0;           
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return -1;  // this will never happen just returning in the r=end to it doesn't give error
    }
};

// qn: https://leetcode.com/problems/find-the-duplicate-number/