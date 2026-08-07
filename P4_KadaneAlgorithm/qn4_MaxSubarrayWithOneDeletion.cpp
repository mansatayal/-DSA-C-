#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int sz = arr.size();
        if(sz == 1) return arr[0];

        int ans = arr[0];
        int onedelete = 0;
        int nodelete = arr[0];

        for(int i = 1; i < sz; i++){
            int delprev = onedelete + arr[i];
            onedelete = max(nodelete, delprev);     // nodelete : delete arr[i] 
            nodelete = max(nodelete + arr[i] , arr[i]);     // either take the whole array with no deltes till arr[i] or just arr[i]
            ans = max({ans, onedelete, nodelete});
        }
        return ans;
    }
};

// qn: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
