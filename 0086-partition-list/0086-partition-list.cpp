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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)  return head;
        
        
        ListNode* less=new ListNode();
        ListNode* tail=less;
        ListNode* gret=new ListNode();
        ListNode* head2=gret;
        
        while(head)
        {
            if(head->val<x)
            {
                tail->next=head;
                tail=head;
            }
            else{
                gret->next=head;
                gret=head;
            }
            head=head->next;
        }
        
        gret->next=NULL;
        
        if(less->next==NULL) return head2->next;
        
        tail->next=head2->next;
        
        return less->next;
    }
};