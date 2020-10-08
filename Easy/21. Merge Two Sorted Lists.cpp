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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1 || !l2) return !l1 ? l2 : l1; 
        ListNode *newlist = new ListNode(0);
        ListNode *head = newlist;    
        while(l1!=NULL && l2!=NULL) {
            if(l1->val < l2->val)  {
               head->next=l1;
               l1=l1->next;
            }
            else{
                head->next=l2;
                l2=l2->next;
            }
            head=head->next; //to move answer list forward in order to store next element
        }
        head->next = l1==NULL ? l2 : l1;
        return newlist->next;
    }
};