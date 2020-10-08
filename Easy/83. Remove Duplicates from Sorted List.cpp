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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* new_head = head;
        while(new_head && new_head->next) {
            if(new_head->val == new_head->next->val) {
                new_head->next = new_head->next->next;
            }
            else new_head=new_head->next;
            //we do else, because if it is 1->1->1
            //we will check 1->1 first and connect 1st to 3rd
            //now we need to check 1st and 3rd also again
            //we cannot just iterate forward to the next w/o checking
            //hence we have added it as if..else
        }
        return head;
    }
};