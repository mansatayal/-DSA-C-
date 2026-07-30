#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

// dynamic
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int low = 0;
        int high = 0;
        int count = INT_MIN;
        unordered_map <char,int> f;
        
        while(high < s.length()){
            // add
            f[s[high]]++;
            
            while(f.size() > k){
                // shrink
                
                f[s[low]]--;
                
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                
                low++;
            }
            
            // store and check
            if(f.size() == k){
                int len = high - low +1 ;
                count = max(count, len);      
            }
            
            high++;
        }
        
        if(count == INT_MIN){
            return -1;
        }
        else{
            return count;
        }
        
    }
};


/*Question : Longest Substring with K Uniques
link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26
*/