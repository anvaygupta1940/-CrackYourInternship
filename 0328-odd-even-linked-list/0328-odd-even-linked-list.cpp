/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* evenHead=new ListNode();
        ListNode* eventail=evenHead;
        ListNode* oddHead=new ListNode();
        ListNode* oddtail=oddHead;
        
        int ind=0;
        while(head)
        {
            if(ind%2==0)
            {
                eventail->next=head;
                eventail=head;
            }
            else{
                oddtail->next=head;
                oddtail=head;
            }
            
            head=head->next;
            ind++;
        }
        
        eventail->next=oddHead->next;
        oddtail->next=NULL;
        return evenHead->next;
        
    }
};