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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 1) return head;

        ListNode dummy(0,head);
        ListNode* link = &dummy;
        ListNode* count;

        while(true){
            count = link -> next;
            if(count == nullptr) return dummy.next;     //multiple of k nodes

            // check if k nodes exists
            for(int i = 1; i < k; i++){
                if(count -> next == nullptr){
                    return dummy.next;
                }
                else count = count -> next;
            }
            // count is on kth element now that will be connected to the dummy node

            // these two nodes will be used to link the head node to the next of the end of k group and more
            ListNode* end = link -> next; 
            ListNode* nodeaftergroup = count -> next;

            ListNode* prev = link -> next;
            ListNode* curr = prev -> next;

            while(prev != count){
                ListNode* nxt = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = nxt;
            }

            end -> next = nodeaftergroup;
            link -> next = count;
            link = end;
            
        }

    }
};


// qn: https://leetcode.com/problems/reverse-nodes-in-k-group/description/