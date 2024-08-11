class Solution {
public:
    int helper(int n)
    {
        // base case
        if(n<=1) return 1;
        
        int ans=0;
        for(int node=1;node<=n;node++)
        {
            ans+=helper(node-1)*helper(n-node);
        }
        
        return ans;
    }
    int numTrees(int n) {
        return helper(n);
    }
};