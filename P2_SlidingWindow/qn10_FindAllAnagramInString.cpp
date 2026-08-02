#include <iostream>
#include <vector>
using namespace std;

// fixed
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> vp(26,0);
        for(char c : p) vp[c - 'a']++;

        int req = 0;
        for(int i : vp) if(i > 0) req++;

        int found = 0;
        vector <int> vs(26,0);
        int low = 0;
        int high = 0;

        vector <int> ans;

        while(high < s.size()){
            unsigned char c = s[high] - 'a';
            vs[c]++;

            if(vp[c] > 0 && vs[c] == vp[c]) found++;

            // if exceeds p size shrink from left
            if(high - low + 1 > p.size()){
                unsigned char lc = s[low] - 'a';
                if(vp[lc] > 0 && vs[lc] == vp[lc]) found--;
                vs[lc]--;
                low++;
            }

            // if equals add 
            if(high - low + 1 == p.size() && req == found){
                ans.push_back(low); 
            }
            high++;
        }

        return ans;
    }
};


// qn: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/