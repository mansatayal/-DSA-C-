#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int sz = arr.size();
        if(k > sz) return -1;
        
        long long low = *max_element(arr.begin(), arr.end());   // why not the last element? bacause the array isn't sorted
        long long high = 0;
        for(int i : arr){
            high += i;
        }
        
        if (k == 1) return high;
        
        long long res = INT_MAX;
        
        while(high >= low){
            long long mid = low + ((high - low)/2);
            int cnt = 1;
            long long add = 0;
            
            for(int i = 0; i < sz; i++){
                
                if(add + arr[i] <= mid) add += arr[i];
                else{
                    cnt++;
                    add = arr[i];
                }
                
                if(cnt > k) break;
                
            }
            
            if(cnt <= k){
                res = min(mid, res);    // mid is the actual partition between
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
        
        return (int)res;

    }
};

// qn: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1    