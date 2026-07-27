#include <iostream>
#include <vector>
using namespace std;

// fixed sliding window
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        if(k == 0){
            return 0;
        }
        
        int low = 0;
        int high = k - 1;
        int sum = 0;
        
        // sum of first subset 
        for(int i = low; i <= high; i++){
            sum += arr[i];
        }
        low++;
        high++;
        
        // sum of other subsets
        while(high < arr.size()){
            int s = sum - arr[low - 1] + arr[high];
            if(s > sum){
                sum = s;
            }
            low++;
            high++;
        }
        
        return sum;
        
    }
};

/* Question: Max Sum Subarray of size K
link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.
Note: A subarray is a contiguous part of any given array.

Examples:
Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.

Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.

Input: arr[] = [100, 200, 300, 400], k = 1
Output: 400
Explanation: arr3 = 400, which is maximum.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
1 ≤ k ≤ arr.size()

*/