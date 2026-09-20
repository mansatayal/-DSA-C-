#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while(high >= low){
            int mid = low + ((high - low)/2);

            if(arr[mid] < arr[mid+1]) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
};

// qn: https://leetcode.com/problems/peak-index-in-a-mountain-array/