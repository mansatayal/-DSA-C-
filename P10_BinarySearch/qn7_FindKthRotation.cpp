#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0;
        int high = arr.size() - 1;
        
        while(high > low){
            int mid = low + ((high - low)/2);
            
            if(arr[mid] > arr[high]) low = mid +1;
            else high = mid;
        }
        
        return low;
        
    }
};


// qn: https://www.geeksforgeeks.org/problems/rotation4723/1