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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //if(!headA || !headB) return NULL;
        unordered_map<ListNode*,int> intersect;
        while(headA!=NULL) {
            intersect[headA]++;
            headA=headA->next;  
        }
        while(headB!=NULL) {
            intersect[headB]--;
            if(intersect[headB]==0) break;
            headB=headB->next;
        }
        return headB;
    }
};