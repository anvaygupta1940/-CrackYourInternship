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
    ListNode* reverseLL(ListNode* start)
    {
        ListNode* prev=NULL;
        ListNode* forw=NULL;
        
        while(start)
        {
            forw=start->next;
            start->next=prev;
            prev=start;
            start=forw;
        }
        
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* Lprev=NULL;
        ListNode* temp=head;
        while(left>1)
        {
            Lprev=temp;
            temp=temp->next;
            left--;
        }
        ListNode* start=temp;
        
        
        ListNode* Rnext=NULL;
        temp=head;
        while(right>1)
        {
            temp=temp->next;
            right--;
        }
        Rnext=temp->next;
        temp->next=NULL;
        
        
        ListNode* H=reverseLL(start);
        
        ListNode* tail=H;
        while(tail->next) tail=tail->next;
        
        tail->next=Rnext;
        if(Lprev==NULL) return H;
        
        Lprev->next=H;
        return head;
        
        
    }
};