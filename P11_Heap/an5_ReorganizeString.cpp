#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map <char,int> h;
        for(auto i : s) h[i]++;

        priority_queue <pair<int,char>, vector<pair<int,char>>> pq;

        for(auto [element, freq] : h) pq.push({freq, element});

        int cnt = 0;
        string ans;

        while(!pq.empty()){
            pair<int, char> p = pq.top();               // create a copy of top
            if(cnt == 0 || ans[cnt - 1] != p.second){
                pq.pop();                               // pop top so we can edit it
                ans.push_back(p.second);                // push and decrement 
                cnt++;
                p.first--;

                if(p.first > 0) pq.push(p);             // push the updated value 
            }
            else{
                pq.pop();                               // pop p 
                if(pq.empty()) return "";      // queue empty and we're left with p hence no sol exists

                pair<int,char> p2 = pq.top();       //copy the next element
                pq.pop();                           // pop it so we can update it later 
                ans.push_back(p2.second);           // element would be different so push it direclty 
                cnt++;
                p2.first--;

                if(p2.first > 0) pq.push(p2);
                pq.push(p);
            }
        }

        return ans;
    }
};


// qn: https://leetcode.com/problems/reorganize-string/
