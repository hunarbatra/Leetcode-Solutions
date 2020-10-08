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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode *slow=dummy, *fast=dummy;
        for(int i=0;i<n+1;i++) fast=fast->next;
        while(fast!=NULL) {
            fast=fast->next; slow=slow->next;
        }
        slow->next=slow->next->next;
        //delete fast;
        return dummy->next;
    }
};