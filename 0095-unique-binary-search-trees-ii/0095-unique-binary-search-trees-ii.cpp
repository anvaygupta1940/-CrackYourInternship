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
    vector<TreeNode*> solve(int start,int end)
    {
        vector<TreeNode*>ans;
        
        // base cases
        if(start>end)
        {
            ans.push_back(NULL);
            return ans;
        }
        
        if(start==end)
        {
            ans.push_back(new TreeNode(start));
            return ans;
        }
        
        
        
        
        for(int node=start;node<=end;node++)
        {
            vector<TreeNode*>lf=solve(start,node-1);
            vector<TreeNode*>rg=solve(node+1,end);
            
            for(auto l:lf)
            {
                for(auto r:rg)
                {
                    TreeNode* root=new TreeNode(node);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};