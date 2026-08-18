#include <iostream>
#include <vector>
using namespace std;

// 2 pointer + merge intervals 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int sz1 = firstList.size();
        int sz2 = secondList.size();
        if(sz1 == 0 || sz2 == 0) return {};

        vector<vector<int>> ans;
        int i = 0, j = 0;

        while(i < sz1 && j < sz2){

            int low = max(firstList[i][0], secondList[j][0]);   // max of start
            int high = min(firstList[i][1], secondList[j][1]);  // min of end 

            if(low <= high) ans.push_back({low,high});

            // to check if the number in the end position of each interval is a part of the intersaction
            if(firstList[i][1] < secondList[j][1])  i++;   
            else j++;

        }

        return ans;
    }
};

// qn: https://leetcode.com/problems/interval-list-intersections/