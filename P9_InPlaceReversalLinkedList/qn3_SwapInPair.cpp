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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode dummy(0,head);
        ListNode* link = &dummy;

        while(link -> next != nullptr && link -> next -> next != nullptr){
            ListNode* first = link -> next;
            ListNode* second = first -> next;
            
            first -> next = second -> next;
            second -> next = first;
            link -> next = second;

            link = first;
        }

        return dummy.next;

    }
};



// link: https://leetcode.com/problems/swap-nodes-in-pairs/