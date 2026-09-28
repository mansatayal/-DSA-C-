#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  //number of rows
        int n = matrix[0].size();       // number of columns

        if(target > matrix[m - 1][n - 1] || target < matrix[0][0]) return false;
        
        // find row
        int l = 0;
        int row = m - 1;

        if(m > 0){
            while(l <= row){
                int mid = l + ((row - l)/2);

                if(target <= matrix[mid][n-1]) row = mid - 1;   // check the last element of the row 
                else l = mid + 1;
            }
        }

        // l is now the row number
        row = l;

        int low = 0;
        int high = n - 1;

        while(high >= low){
            int mid = low + ((high - low)/2);

            if(target == matrix[row][mid]) return true;
            else{
                (target > matrix[row][mid])? low = mid + 1 : high = mid - 1;
            }
        }

        return false;
    }
};

// qn: https://leetcode.com/problems/search-a-2d-matrix/description/