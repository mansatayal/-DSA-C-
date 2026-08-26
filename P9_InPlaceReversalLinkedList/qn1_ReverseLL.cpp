#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head ;

        while(curr != nullptr){
            ListNode* nxt = curr -> next;       // store next element
            curr -> next = prev;                // link current element with previous
            prev = curr;                        // previous as current
            curr = nxt;                         // current as the stored element
        }

        return prev;    // curr is nullptr here 
    }
};

// qn: https://leetcode.com/problems/reverse-linked-list/