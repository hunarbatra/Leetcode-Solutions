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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        stack<ListNode*> s; 
        queue<ListNode*> q; 
        int fast = 0, slow = 0;
        
        ListNode *p = head; //for traversing till end to fill up stack and queue
        //also takes the fast int to end of list
        while(p!=NULL){
            s.push(p);
            q.push(p);
            p = p->next;
            fast++;
        }
    
        ListNode *dummyHead=new ListNode(0);
        ListNode *h = dummyHead;
        while(slow < fast)
        {
            h->next = q.front();
            q.front()->next = s.top();
            h = s.top();
            q.pop();
            s.pop();
            slow += 2;
        }
        h->next = NULL;
    }
};