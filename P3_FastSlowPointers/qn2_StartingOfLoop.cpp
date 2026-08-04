#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || head -> next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr){

            // finding cycle 
            slow = slow -> next;
            fast = fast -> next -> next;

            if(fast == slow){   // cycle found
                slow = head;
                while(slow != fast){
                    slow = slow -> next;    // head -> start of loop
                    fast = fast -> next;    // fast is at the meeting point and it'll take exactly as much time as slow will take to reach the start of the loop
                }
                return slow;
            }  
        }

        return nullptr;      // no cycle found
    }
};

/* Floyd's Cycle Detection Algorithm (also called the tortoise and hare algorithm)

l1 = head to starting point of loop
l2 = starting point of loop to meetup point of loop
n = number of rounds fast took
C = number of nodes in loop

slow travels: l1 + l2 distance
fast travels: l1 + n.C + l2 distance

fast travels double of slow hence:

fast travels = 2 * slow travels
l1 + n.C + l2 = 2(l1 + l2)
l1 + n.C + l2 = 2l1 + 2l2
n.C = l1 + l2       (l1 and l2 cancels with one of each l1 and l2 in right)
=>> l1 = n.C - l2
hence when after finding the loop via a meeting point we set slow to head and keep fast at the meeting point and move both with one step at a time and when they meet now they're at the stating point of loop

*/

// qn: https://leetcode.com/problems/linked-list-cycle-ii/