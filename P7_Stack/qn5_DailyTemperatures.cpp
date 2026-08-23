#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// basically next greater without circular vector
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        vector <int> ans(sz,0);
        stack<int> s;

        ans[sz - 1] = 0;                    // last day will always be 0
        s.push(sz-1);         // push the ondex of last element in the stack

        for(int i = sz - 2; i >= 0; i--){
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]) s.pop();  

            ans[i] = s.empty()? 0 : s.top() - i;

            s.push(i);      // push index because we need to find the number of days 
        }

        return ans;
    }
};


// qn: https://leetcode.com/problems/daily-temperatures/