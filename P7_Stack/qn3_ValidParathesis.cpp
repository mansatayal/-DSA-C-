#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if(s.size() % 2 != 0) return false;     // odd paranthesis can't be valid

        stack <char> st;
        unordered_map <char, char> match ={     //we need to match the closing hence [ first
            {')', '('},                         
            {'}', '{'},
            {']', '['}
        };

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){       //opening
                st.push(c);
            }
            else{                                       //closing
                if(st.empty() || st.top() != match[c]){
                    return false;             //if empty: string started with closing bracket
                }

                st.pop();                     // matches the opening bracket
            }
        }

        return st.empty();      // if empty every opening have been closed correctly
    }
};


// qn: https://leetcode.com/problems/valid-parentheses/