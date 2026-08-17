#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int sz = intervals.size();
        int i = 0;
        vector <vector<int>> ans;

        // insert
        while(i < sz && intervals[i][1] < newInterval[0]){  //when >= stop pushing go to merge
            ans.push_back(intervals[i]);
            i++;
        }

        int s = newInterval[0];
        int e = newInterval[1];

        while(i < sz && e >= intervals[i][0] ){
            // overlap
            s = min(s, intervals[i][0]);
            e = max(intervals[i][1],e);
            i++;
        }
        ans.push_back({s,e});

        // rest is not overlapped so just add them as it is 
        while(i < sz){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

// qn: https://leetcode.com/problems/insert-interval/