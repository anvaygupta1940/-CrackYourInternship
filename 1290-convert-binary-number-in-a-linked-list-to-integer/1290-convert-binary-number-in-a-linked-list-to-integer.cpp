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
    pair<int,int>helper(ListNode* head){
        
        if(head==NULL) return {0,0};
        
        auto it=helper(head->next);
        int sum=it.first;
        auto ind=it.second;
        
        sum=sum+(head->val)*pow(2,ind);
        return {sum,ind+1};
    }
    int getDecimalValue(ListNode* head) {
        auto ans=helper(head);
        return ans.first;
    }
};