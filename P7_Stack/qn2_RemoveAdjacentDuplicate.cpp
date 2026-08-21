#include <iostream>
using namespace std;


// using stack's principle in string 
class Solution {
public:
    string removeDuplicates(string s) {
        string st;

        for(char c : s){
            if(st.empty() || st.back() != c){
                st.push_back(c);
            }
            else{
                st.pop_back();
            }
        }

        return st;
    }
};


// qn: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/