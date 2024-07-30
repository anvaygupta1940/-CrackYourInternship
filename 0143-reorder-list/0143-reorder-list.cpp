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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* forw=NULL;
        
        while(head){
            forw=head->next;
            head->next=prev;
            prev=head;
            head=forw;
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* head2=slow->next;
        slow->next=NULL;
        head2=reverseLL(head2);
        
        while(head2!=NULL)
        {
            ListNode* head_next=head->next;
            ListNode* head2_next=head2->next;
            
            head->next=head2;
            head2->next=head_next;
            
            head=head_next;
            head2=head2_next;
        }
        
        
    }
};