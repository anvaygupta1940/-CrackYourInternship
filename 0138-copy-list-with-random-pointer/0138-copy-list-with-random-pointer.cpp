/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*,Node*>& mpp)
    {
        // base case
        if(head==NULL) return NULL;
        
        Node* newHead=new Node(head->val);
        mpp[head]=newHead;
        newHead->next=helper(head->next,mpp);
        
        newHead->random=mpp[head->random];
        
        return newHead;
        
        
    }
    Node* copyRandomList(Node* head) {
       unordered_map<Node*,Node*>mpp;
        return helper(head,mpp);
        
    }
};