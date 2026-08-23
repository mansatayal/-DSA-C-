#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char,int>> st;

        for(char c : s){
            if(!st.empty() && c == st.top().first){
                // increment the count of the pair
                auto p = st.top(); 
                st.pop();
                p.second++;
                st.push(p);
            }
            else{
                st.push({c,1});
            }

            if(st.top().second == k) st.pop();
        }

        string ans;
        while(!st.empty()){
            auto [ch, cnt] = st.top();
            st.pop();

            ans.append(cnt, ch);    // eg. cnt is 3 and ch is a then append aaa
        }

        reverse(ans.begin(), ans.end());   // stack pops from back hence we need to reverse it

        return ans;
    }
};

// qn: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

