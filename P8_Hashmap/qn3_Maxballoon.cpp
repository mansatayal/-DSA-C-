#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int sz = text.size();
        if(sz < 7) return 0;

        unordered_map <char, int> b = {{'b', 1}, {'a',1}, {'l',2}, {'o', 2}, {'n', 1}};
        unordered_map <char, int> m;
        int count = INT_MAX;
        for(int i = 0; i < sz; i++) m[text[i]]++;

        for(auto i : b){
            // if m['b'] = 4 then only 4/2 = 2 balloon is possible
            int possible = m[i.first] / i.second;   
            count = min(count, possible);
        }
        return count;
        
    }
};

// qn: https://leetcode.com/problems/maximum-number-of-balloons/