#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> r;
        unordered_map <char, int> m;

        for(auto i : ransomNote) r[i]++;
        for(auto i : magazine) m[i]++;

        for(auto i : ransomNote){
            if(r[i] > m[i]) return false;
        }
        return true;

    }
};

// qn: https://leetcode.com/problems/ransom-note/