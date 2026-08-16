#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// in place
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();

        if (sz == 1) return intervals;

        for(int i = 0; i < sz - 1;){
            if(intervals[i][1] >= intervals [i+1][0]){
                // overlapping exists
                // i,0 is the smallest and max(i,1 and i+1,1)   this ensures a perfect interval with no overlapping
                intervals[i + 1] [0] = intervals[i] [0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals.erase(find(intervals.begin(), intervals.end(),intervals[i]));
                sz--;
                // don't increment i we need to check the interval we just created
            }
            else i++;   // increment only if no overlapping found 

        }

        return intervals;
    }
};


// using another vector
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        if (sz == 1) return intervals;

        vector<vector<int>> ans;
        int s = intervals[0][0];
        int e = intervals[0][1];


        for(int i = 1; i < sz; i++){
            if(e >= intervals[i][0]){
                // overlapping exists
                e = max(e, intervals[i][1]);
            }
            else{
                // no overlapping 
                ans.push_back({s,e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        ans.push_back({s,e});

        return ans;
    }
};

// qn: https://leetcode.com/problems/merge-intervals/