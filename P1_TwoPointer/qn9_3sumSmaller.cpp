#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        int ans = 0;
        
        
        for(int i = 0; i < sz; i++){
            int j = i+1;
            int k = sz - 1;
            
            while( k > j){
                int s = arr[i] + arr[j] + arr[k];
                
                if(s < sum){        // if smaller add j + 1 to k 
                    ans += k - j;
                    j++;
                }
                else{               // sum equal or greater we need to move to left only
                    k--;
                }
            }
        }
        
        return ans;
    }
};

/*  QUESTION: Triplets with Smaller Sum
link: https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

Given an array arr[] of distinct integers and a value sum, find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

Examples :
Input: sum = 2, arr[] = [-2, 0, 1, 3]
Output:  2
Explanation: Triplets with sum less than 2 are (-2, 0, 1) and (-2, 0, 3). 

Input: sum = 12, arr[] = [5, 1, 3, 4, 7]
Output: 4
Explanation: Triplets with sum less than 12 are (1, 3, 4), (5, 1, 3), (1, 3, 7) and (5, 1, 4).

Constraints:
1 ≤ sum ≤ 105
3 ≤ arr.size() ≤ 103
-103 ≤ arr[i] ≤ 103

*/