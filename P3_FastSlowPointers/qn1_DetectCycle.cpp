#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || head -> next == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != nullptr && fast -> next != nullptr){
            if(slow == fast) return 1;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return 0;
    }
};

// qn: https://leetcode.com/problems/linked-list-cycle/ 