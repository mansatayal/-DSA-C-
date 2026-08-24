#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char,int>> st;

        // using a reverse loop so the elements stored in the stack can be retrived without using reverse 
        for(int c = s.size() - 1; c >= 0; c--){
            if(!st.empty() && s[c] == st.top().first){
                // increment the count of the pair
                auto p = st.top(); 
                st.pop();
                p.second++;
                st.push(p);
            }
            else{
                st.push({s[c],1});
            }

            if(st.top().second == k) st.pop();
        }

        string ans;
        while(!st.empty()){
            // eg. append(3,a) is add aaa
            ans.append(st.top().second, st.top().first);
            st.pop();
        }

        return ans;
    }
};


// qn: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
