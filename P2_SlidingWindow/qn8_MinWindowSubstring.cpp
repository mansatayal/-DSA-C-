#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size(), n = t.size(); 
        if(m == 0 || m < n) return "";  //if s is empty or smaller then t then ans doesn't exist
        
        vector<int> tarr(256, 0);
        for(int c : t) tarr[c]++;   // array with count for every letter in t

        int required = 0; // number of distinct chars in t that needs to be matched (not n)
        for(int i = 0; i < 256; i++) if(tarr[i] > 0) required++;

        vector<int> sarr(256,0);
        int found = 0;        // number of chars in s that are being matched
        int low = 0;
        int bestlen = INT_MAX;
        int beststart = 0;

        for(int high = 0; high < m; high++){
            unsigned char c = s[high];
            sarr[c]++;   // increment value in sarr wrt s[high]

            // increment found only if the match is found (eg. if there are 3 duplicates of a then found will increment only when sarr[c] == 3)
            if(tarr[c] > 0 && tarr[c] == sarr[c]) found++;     

            while(found == required){     //correct info
                // store
                    if(high - low + 1 < bestlen){
                        bestlen = high - low + 1;
                        beststart = low;    //track best start
                    }

                // reduce
                unsigned char lc = s[low];
                sarr[lc]--;

                if(tarr[lc] > 0 && tarr[lc] > sarr[lc]) found--;  //sarr doesn't have enoungh chars

                low++;
            }
        }

        return bestlen == INT_MAX ? "" : s.substr(beststart, bestlen);

    }
};

/* Question: Minimum Window Substring
link: https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 
Follow up: Could you find an algorithm that runs in O(m + n) time?
*/