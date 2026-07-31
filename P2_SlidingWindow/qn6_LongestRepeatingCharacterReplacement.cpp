#include <iostream>
#include <vector>
using namespace std;

// dynamic
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector <int> f(26,0);       //places for 26 alphabets with count 0 intially;
        int low = 0;
        int count = 0;
        int ans = 0;

        for(int high = 0; high < s.size(); high++){
            f[s[high] - 'A']++;       // ascii value for A is 65 we need to alter it to 0
            count = max(count, f[s[high] - 'A']);

            while((high - low + 1) - count > k){   // window size - count > k to know if it's achievable
                f[s[low] - 'A']--;
                low++;
            }

            ans = max(ans, (high - low + 1));
        }

        return ans;
    }
};

/* Question: Longest Repeating Character Replacement
link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

Constraints:
1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

*/