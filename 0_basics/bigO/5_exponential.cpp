// O(2 ^ n) -> Binary decision per element. For each element you make an in and out choice and each choice doubles the number of paths.     (2 branches)

// O(C ^ n )    c = any constant    c is number of braches  

#include <iostream>
#include <vector>
using namespace std;

int recursion(int i, vector<int>& nums) {
    // Base case
    if (i >= nums.size())
        return 0;

    int branch1 = recursion(i + 1, nums);
    int branch2 = recursion(i + 2, nums);

    return branch1 + branch2;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    recursion(0, nums);

    return 0;
}