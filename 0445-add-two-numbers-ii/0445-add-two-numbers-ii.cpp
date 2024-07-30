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
    ListNode* reverseLL(ListNode* curr)
    {
        ListNode* prev=NULL;
        ListNode* forw=NULL;
        
        while(curr)
        {
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        
        int carry=0;
        
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int sum=carry;
            
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            
            carry=sum/10;
            ListNode* newNode=new ListNode(sum%10);
            tail->next=newNode;
            tail=newNode;
        }
        
        ListNode* head=reverseLL(dummy->next);
        return head;
        
    }
};