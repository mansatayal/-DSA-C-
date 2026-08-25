#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int sz = s.size();
        if(sz == 1) return 0;

        unordered_map <char,int> m;

        for(int i = 0; i < sz; i++){
            m[s[i]]++;      // increment the count of the char
        }

        for(int i = 0; i < sz; i++){
            if(m[s[i]] == 1) return i;      // check the char 
        }

        return -1;     // if no value is equal to 1 then no unique element is there
    }
};


// qn: https://leetcode.com/problems/first-unique-character-in-a-string/