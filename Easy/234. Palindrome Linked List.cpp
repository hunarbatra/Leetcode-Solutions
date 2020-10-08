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
    bool isPalindrome(ListNode* head) {    
        stack<ListNode*> nodestack;
        ListNode* p = head;
        while(p) {
            nodestack.push(p);
            p=p->next;
        }
        while(head) {
            if(head->val != nodestack.top()->val) {
                return false;
            }
            nodestack.pop();
            head=head->next;
        }
        return true;
    }
};