#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
    int first(vector<int>& nums ,int low, int high, int target){
        // check left
        int best = 0;

        while(high >= low){
            int mid = low + ((high - low) / 2);

            if(nums[mid] == target){
                best = mid;
                high = mid - 1;
            }
            else low = mid + 1;
            // value greater than target is not possible as we're looking in the left of the list
        }
        return best;
    }

    int last(vector<int>& nums, int low, int high, int target){
        // check right;
        int best = 0;

        while(high >= low){
            int mid = low + ((high - low) / 2);

            if(nums[mid] == target){
                best = mid;
                low = mid + 1;
            }
            else high = mid - 1;
            // value smaller than target is not possible as we're looking in the right of the list
        }
        return best;
    }  

  
    int countFreq(vector<int>& arr, int target) {
        if(arr.empty() || arr[0] > target) return 0;
        
        int low = 0;
        int high = arr.size() - 1;
        
        while(high >= low){
            int mid = low + ((high - low)/2);
            
            if(arr[mid] == target){
                int f = first(arr, low, high, target);
                int e = last(arr, low, high, target);
                
                return e - f + 1;
            }
            else{
                (arr[mid] > target)? high = mid - 1: low = mid + 1;
            }
        }
        
        return 0;
    }
};

// qn: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1