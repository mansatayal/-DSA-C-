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
    ListNode* rotateRight(ListNode* head, int k) {

        if(k == 0 || head == nullptr || head -> next == nullptr) return head;

        ListNode* curr = head;
        int len = 1;        // start from head
        // len
        while(curr -> next != nullptr){
            curr = curr -> next;
            len++;
        }
        ListNode* tail = curr;  // last element of the list 

        k = k % len;        // reduce k acc to length
        if (k == 0) return head;

        curr = head;
        for(int i = 0; i < len - k - 1; i++){
            curr = curr -> next;
        }
        // now curr is at the element you need to cut it from 

        ListNode* newhead = curr -> next;
        curr -> next = nullptr;
        tail -> next = head;

        return newhead;
        
    }
};


// qn: https://leetcode.com/problems/rotate-list/