#include <iostream>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // if none or only one element exists return head
        if(head == nullptr || head -> next == nullptr){
            return head;
        }

        ListNode* i = head;
        ListNode* j = i -> next;

        while(j != nullptr){
            if(i -> val == j -> val){   //if duplicate found
                j = j -> next;          // skip the node
            }
            else if(i -> val != j -> val){     // unique value found
                i -> next = j;                 // connnect both the unique values and adjust variables
                i = j;
                j = i -> next;
            }
        }
        i -> next = j;      //handles the duplicate values in the end of the list 
        return head;
    }
};


// not a two pointer approach exactly but kinda works on the same principal
// better space complexity
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // if none or only one element exists return head
        if(head == nullptr || head -> next == nullptr){ 
            return head;
        }

        ListNode* curr = head;
        
        while(curr != nullptr && curr -> next != nullptr){
            if(curr -> val == curr -> next -> val){     // if duplicate found
                curr -> next = curr -> next -> next;    // skip to the next element
            }
            else{
                curr = curr -> next;    // if no duplicate found move forward
            }
        }
        return head;
        
    }
};

/*  QUESTION: Remove Duplicates from Sorted List
link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/