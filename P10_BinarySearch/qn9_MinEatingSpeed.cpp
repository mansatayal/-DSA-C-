#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int sz = piles.size();
        int low = 1;    // min banana to eat
        int high = *max_element(piles.begin(), piles.end());    // max is the greatest element in the list
        int res = high;

        if(res == h) return res;

        while(high >= low){
            int mid = low + ((high - low) / 2);
            long long cnt = 0;

            for(int i = 0; i < sz; i++){

                cnt += piles[i] / mid;      // bananas in the pile / mid
                if(piles[i] % mid != 0) cnt++;  // if remainder remains you must add an one more hr
                
                if(cnt > h) break;      
            }

            if(cnt > h) low = mid + 1;
            else{
                res = min(res, mid);        // store the next best
                high = mid - 1;             // try another value
            }
        }

        return res;


    }
};

// qn: https://leetcode.com/problems/koko-eating-bananas/