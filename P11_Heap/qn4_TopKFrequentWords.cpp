#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // asks if a is worse than b
    struct cmp{
        bool operator()(const pair<int,string> &a, const pair<int, string> &b){
            if(a.first != b.first) return a.first > b.first;    // higher freq = better
            return a.second < b.second;                         // same freq ; smaller word = better 
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int> m;
        for(auto i : words) m[i]++;

        priority_queue <pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for(auto [word, freq] : m){
            if(pq.size() < k){
                pq.push({freq, word});
                continue;
            }

            if(cmp()({freq, word}, pq.top())){
                pq.pop();
                pq.push({freq, word});
            }
        }

        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};


// qn: https://leetcode.com/problems/top-k-frequent-words/