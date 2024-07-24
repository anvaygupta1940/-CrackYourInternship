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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head ==NULL || head->next==NULL) return head;
        ListNode* newHead=head;
        ListNode* ans=head;
        head=head->next;
        
        while(head){
            
            if(newHead->val==head->val) head=head->next;
            else{
                newHead->next=head;
                newHead=head;
                head=head->next;
            }
        }
        
        newHead->next=NULL;
        return ans;
    }
};