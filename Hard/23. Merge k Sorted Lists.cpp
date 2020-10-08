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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     /*   priority_queue<int, vector<int>, greater<int>> minheap; //to implement minheap
        //only using priority_queue<int> performs a max heap by defaul
        for(ListNode *head : lists)
        {
            while(head!=NULL)
            { 
                minheap.push(head->val);
                head=head->next;
            }
        }
        
        ListNode *dummy = new ListNode(0); //dummy list which will have all the nodes
        ListNode *head = dummy;
        while(!minheap.empty())
        {
            head->next = new ListNode(minheap.top());
            minheap.pop();
            head=head->next;
        }
        return dummy->next; */
        vector<int> sortit;
        for(ListNode *head : lists) //O(n^2)
        {
            while(head!=NULL)
            {
                sortit.push_back(head->val);
                head=head->next;
            }
        }
        sort(sortit.begin(),sortit.end(), [](int a,int b){return a>b;}); 
        // O(nlgn) and O(n^2) in worst case
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(!sortit.empty())
        {
            head->next= new ListNode(sortit.back());
            sortit.pop_back();
            head=head->next;
        }
        return dummy->next;
    }
};