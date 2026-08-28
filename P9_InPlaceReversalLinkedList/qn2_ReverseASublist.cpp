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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right) return head;

        // dummy is being in case if left == 1 then without dummy node both start and leftstart should be pointing towards the same node which leads to collisions 
        ListNode dummy(0, head);
        ListNode* start = &dummy;

        for (int i = 1; i < left; i++)
            start = start->next;

        // now start is the element just before left and we need to connect rhis
        // node with the next of right

        ListNode* leftstart = start->next; // left we need to connect it to the last of the list later

        // for reversal:
        ListNode* prev = leftstart;
        ListNode* curr = prev->next;
        for (int i = 1; i < right - left + 1; i++) { // stop when curr is right
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        leftstart->next = curr;
        start->next = prev; // curr is right

        return dummy.next;  //. because dummy is a object not pointer 
    }
};

// qn: https://leetcode.com/problems/reverse-linked-list-ii/