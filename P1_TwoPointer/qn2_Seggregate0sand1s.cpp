#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int i = 0;
        int j = arr.size() - 1;
        
        while(j > i){
            if(arr[i] == 0 and arr[j] == 0){        // move i cause we need to find a 1 to swap it with
                i++;
            }
            else if(arr[i] == 0 and arr[j] == 1){   //move both w/o doing anything both are in their perfect spot
                i++;
                j--;
            }
            else if(arr[i] == 1 and arr[j] == 0){   // swap and move both
                swap(arr[i], arr[j]);
                i++; 
                j--;
            }
            else if(arr[i] == 1 and arr[j] == 1){   // move j cause we need to find a 0 to swap it with
                j--;
            }
        }
        
    }
};


/*QUESTION - Segregate 0s and 1s
link: https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

Given an array arr[] consisting of only 0's and 1's. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

Examples :

Input: arr[] = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 0, 0, 1, 1, 1, 1, 1].
Input: arr[] = [1, 1]
Output: [1, 1]
Explanation: There are no 0s in the given array, so the modified array is [1, 1]
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 1
*/