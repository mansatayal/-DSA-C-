#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int sz = people.size();
        int boat = 0;
        int low = 0, high = sz - 1;

        while(high >= low ){
            if(people[low] + people[high] <= limit){
                low++;
            }
            high--;     // if lowest + highest can't get a boat give heaviest the boat
            boat++;
        }


        return boat;
    }
};

// qn: https://leetcode.com/problems/boats-to-save-people/