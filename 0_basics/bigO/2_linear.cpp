// O(n) - the running time grows linearly with the size of input
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1,2,3};
    int sum = 0;
    nums.insert(nums.begin()+2, 10);    //insert in middle
    nums.erase(nums.begin()+1);         // remove from middle 
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];     //sum of array
        cout << nums[i] << " ";    //looping

        // searching
        if(nums[i] == 10){
            cout << "found" << endl;
        }
    }

    // building heaps
    // sometimes even nested loops can be O(n) [eg. monotonic stack or sliding window]
}

// adding an element at the 0th element is the worst scenario as then you need to move every element 
// adding in the last is best 
// same goes for removing an element 

// finding the element in the 0th index -> best; last -> worst