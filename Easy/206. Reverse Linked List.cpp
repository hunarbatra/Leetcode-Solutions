/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //iterative
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *previous=NULL, *current=head, *next;
        while(current!=NULL) {
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        return previous;
    }
    
    //recursive
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *reverseListHead = reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return reverseListHead;
    }
};