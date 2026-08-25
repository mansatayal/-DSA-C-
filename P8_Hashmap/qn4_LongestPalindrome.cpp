#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int sz = s.size();

        unordered_map <char, int> m;
        for(auto i : s) m[i]++;

        int even = 0;
        int odd = 0;
        for(auto i : m){
            if(i.second % 2 == 0){      //even
                even += i.second;
            }
            else{                       //odd
                even += i.second - 1;       // odd - 1 is even
                odd = 1;                    // only 1 more number is left
            }
        }

        return even + odd;  // odd can be added once only in the middle of the string 
        
    }
};


// qn: https://leetcode.com/problems/longest-palindrome/