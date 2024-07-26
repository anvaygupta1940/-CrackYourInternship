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
        set<ListNode*>st;
        
        ListNode* head=headA;
        while(head){
            st.insert(head);
            head=head->next;
        }
        
        head=headB;
        
        while(head)
        {
            if(st.find(head)!=st.end()) return head;
            
            head=head->next;
        }
        
        return NULL;
    }
};