/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& pre,int preLow,int preHigh,vector<int>& post,int postLow,int postHigh)
    {
        // base case
        if(preLow>preHigh || postLow>postHigh) return NULL;
        
        TreeNode* root=new TreeNode(pre[preLow]);
        
        if(preLow==preHigh) return root;
        
        // finding preorder 2nd elem in postorder
        int i=postLow;
        while(i<=postHigh)
        {
            if(post[i]==pre[preLow+1]) break;
            
            i++;
        }
        int cnt=i-postLow;
        
        root->left=helper(pre,preLow+1,preLow+cnt+1,post,postLow,i);
        root->right=helper(pre,preLow+cnt+2,preHigh,post,i+1,postHigh);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return helper(preorder,0,n-1,postorder,0,n-1);
    }
};