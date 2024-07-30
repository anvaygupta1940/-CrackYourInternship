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
    int count(ListNode* head){
        
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=count(head);
        if(len==n) return head->next;
        
        int ind=len-n;
        
        ListNode* temp=head;
        while(ind>1)
        {
            temp=temp->next;
            ind--;
        }
        
        temp->next=temp->next->next;
        
        return head;
        
        
    }
};