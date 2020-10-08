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
    ListNode* deleteDuplicatesIterative(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while(pre->next) {
            ListNode* node = pre->next;
            while(node->next && node->val == node->next->val) {
                node = node -> next;
            }
            if(node != pre->next) {
                pre->next = node->next; //delete everything
            } else {
                pre = node; //if there is no duplicate
            }
        }
        return dummy->next;
    }
    
    //Recursive
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next && head->val == head->next->val) {
            while(head->next && head->val == head->next->val) {
                head = head -> next;
            }
            return deleteDuplicates(head->next); //we're basically skipping all same ones
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};