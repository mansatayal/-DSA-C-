#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sol, left, right;


        if(nums[0] < 0){        // if negative elements exists 
            for(int i = 0; i < nums.size(); i++){
                int sqr = nums[i] * nums[i];
                if(nums[i] < 0){    //negative
                    left.push_back(sqr);
                }
                else{               //positive
                    right.push_back(sqr);
                }
            }

            // left -> descending order     right -> ascending order
            int i = left.size() - 1;
            int j = 0;
            while(i > -1 and j < right.size()){
                if(left[i] < right[j]){
                    sol.push_back(left[i]);
                    i--;
                }
                else if(right[j] < left[i]){
                    sol.push_back(right[j]);
                    j++;
                }
                else{       // both elements are equal
                    sol.push_back((left[i]));
                    sol.push_back((right[j]));
                    i--; j++;
                }
            }

            // handle remaining left elements:
            while(i > -1){
                sol.push_back(left[i]);
                i--;
            }

            // handle remaining right eleemts:
            while(j < right.size()){
                sol.push_back(right[j]);
                j++;
            }
        }
        
        else{               // if only positive elements exists
            for(int i = 0; i < nums.size(); i++){
                int sqr = nums[i] * nums[i];
                sol.push_back(sqr);
            }
        }

        return sol;
    }
};


/*QUESTION: Squares of a Sorted Array
link: https://leetcode.com/problems/squares-of-a-sorted-array/description/

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 
Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/