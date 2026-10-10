#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        if(nums.empty()) return {};

        unordered_map <int, int> m;
        for(auto i : nums) m[i]++;      // hash map with value and frequency

        priority_queue <pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> pq;  //min heap

        for(auto [element, freq] : m){

            if(pq.size() < k) {
                pq.push({freq , element});
                continue;
            }

            if(freq <= pq.top().first) continue;        // same greater k logic
            else{
                pq.pop();
                pq.push({freq, element});
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;


        
    }
};

// qn: https://leetcode.com/problems/top-k-frequent-elements/