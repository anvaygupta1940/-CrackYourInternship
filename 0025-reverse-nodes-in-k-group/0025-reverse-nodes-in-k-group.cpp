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
    int lengthLL(ListNode* head)
    {
        if(head==NULL) return 0;
         return 1+lengthLL(head->next);
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=lengthLL(head);
        if(len<k) return head;
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forw=NULL;
        
        int i=0;
        while(i<k)
        {
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
            i++;
        }
        
        head->next=reverseKGroup(curr,k);
        
        return prev;
        
    }
};