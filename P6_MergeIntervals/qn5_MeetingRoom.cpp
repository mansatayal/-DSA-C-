#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// two pointer + merge intervsls 
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int room = 0;
        int ans = 0;
        int i = 0, j  = 0;
        
        int sz = start.size();
        
        if(sz == 1) return 1;
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        while(i < sz && j < sz){
            if(start[i] < end[j]){
                room++;
                ans = max(ans, room);
                i++;
                
            }

            else{
                room--;
                j++;
            }
        }
        return ans;
        
    }
};

// qn: https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1