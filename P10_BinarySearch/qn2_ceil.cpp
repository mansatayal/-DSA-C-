#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() - 1;
        int mid;
        int best = -1;
        
        while(low <= high){
            mid = low + ((high - low) / 2);
            // not returning arr[mid] == x as there can be duplicates and we want the first occurence
            if(arr[mid] >= x){
                best = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return best;
        
    }
};

// qn: https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1