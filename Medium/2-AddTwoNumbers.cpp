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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode(0); //creating a list to store the result
        ListNode* curr = newList; //head for the new list basically
        int carry = 0;
        while(l1!=NULL || l2!=NULL) {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr -> next;
            if(l1 != NULL) l1 = l1 -> next;
            if(l2 != NULL) l2 = l2 -> next;
        }
        if(carry > 0) curr -> next = new ListNode(carry);
        return newList->next;
    }
};