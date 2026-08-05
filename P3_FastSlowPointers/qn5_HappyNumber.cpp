#include <iostream>
using namespace std;


// slow and fast in numbers
class Solution {
public:
    // returns the square sum of digits
    int s(int n){
        int sum = 0;
        while(n > 0){
            int sq = n % 10;
            n = n / 10;
            sum += sq * sq;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(fast != 1){
            slow = s(slow);
            fast = s(fast);
            fast = s(fast);

            if(slow == fast && slow != 1) return false; // loop
        }
        return true;
    }
};

// qn: https://leetcode.com/problems/happy-number/