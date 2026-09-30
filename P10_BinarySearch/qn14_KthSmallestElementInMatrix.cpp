#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (k == 1) return matrix[0][0];

        int m = matrix.size();          // number of rows
        int n = matrix[0].size();       // number of cols

        if(k == m * n ) return matrix[m - 1][n - 1];

        int low = matrix[0][0];
        int high = matrix [m - 1][n - 1];
        int ans = -1;                       //track in matrix elements

        while(low <= high){
            int mid = low + ((high - low)/2);
            int cnt = 0;

            // check how many elements are smaller than equal to mid

            // 1. checks linearly:
            // for(int i = 0; i < m; i++){
            //     for(int j : matrix[i]){
            //         if(j <= mid) cnt++;
            //         else break;
            //     }
            // }

            // 2. optimized approach:
            int row = m - 1;
            int col = 0;

            while(row >= 0 && col < n){
                int val = matrix[row][col];

                if(val <= mid){
                    cnt += row + 1;
                    col++;
                }
                else row--;
            }

            if(cnt >= k){           // as there can be duplicates too
                ans = mid;
                high = mid - 1;
            } 
            else{
                low = mid + 1;
            }

        }

        return ans;

    }
};

// qn: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/