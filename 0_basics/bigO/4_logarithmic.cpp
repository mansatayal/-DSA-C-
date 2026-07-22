// O(log n) -> halving each step
// how many times you can cut an array half until its 1.    (n/2 -> 1) 
// or   how many times you can take the value 1 and multiply it by 2 till you reach n (1 * 2 -> n)
// both the statements is what log actually is 
// log 2^x = log n  =>> x = log n       (the base of the log is 2 here)  

// O(n log n) -> when you split the problem in half repeatedly (log n) but at every level you still touch all n elements(n)
#include <iostream>
#include <vector>
using namespace std;


// binary search
int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> nums = {2, 4, 6, 8, 10, 12, 14};

    int target = 10;

    int index = binarySearch(nums, target);

    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not Found";

    return 0;
}

// heap pop and push -> O(log n)
// binary search on binary search tree -> O(log n)


//O(n log n)
// heap sort 
// =>> popping from the heap -> O(log n) 
// =>> if we have a heap of size n we need to pop till it's emplty -> O(n) times operations 
// ====>> O(n log n)

// merge sort
// and most built-in sorting functions are O(n log n)