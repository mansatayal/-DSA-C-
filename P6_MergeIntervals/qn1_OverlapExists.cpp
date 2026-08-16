#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        sort(intervals.begin(), intervals.end());
        
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i][1] >= intervals[i+1][0]){
                return true;    
                // if end of a interval < start of the other interval then it's definately overlapping
                // eg 1,6  4,8    here 4 is smaller than 6 hence it'll be a part of the second interval too
            }
        }
        return false;
    }
};

// qn: https://www.geeksforgeeks.org/problems/overlapping-intervals--174556/1