#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack <char> st;
        for(int i = 0; i < s.size(); i++){
            st.push(s[i]);
        }

        int i = 0;
        while(!st.empty()){
            s[i] = st.top();
            st.pop();
            i++;
        }
    }
};

// qn: https://leetcode.com/problems/reverse-string/