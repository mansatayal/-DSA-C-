#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0] > target) return false;

        int row = 0;
        int col = matrix[0].size() - 1;

        while(row < matrix.size() && col >= 0){     //starting with bottom left
            if(matrix[row][col] == target) return true;
            else{
                (matrix[row][col] < target)? row++ : col--;
                // if val < target eliminate column 
                // if val > target eliminate row
            }
        }

        return false;
    }
};


// qn: https://leetcode.com/problems/search-a-2d-matrix-ii/