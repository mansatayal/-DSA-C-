// O(n^2) or O(n * m) - the running time is propotional to the sqaure(or k ) of the input
// O(n^k)   k is constant
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};
    
    // traverse a square grid
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    // insertion sort (insert in middle -> n^2)



    // O(n^k)   for example let's take k = 3

    // get every triplet elements in the array
    vector<int> n = {1,2,3,4,5,6};
    for(int i = 0; i < n.size(); i++){
        for(int j = i+1; j < n.size(); j++){
            for (int k = j+1; k < n.size(); k++)
            {
                cout << n[i]<< n[j] << n[k] << " ";
            }    
        }
    }

}