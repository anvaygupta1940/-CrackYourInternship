class Solution {
public:
    bool helper(int ind,int n,vector<int>& nums,vector<int>& dp)
    {
        // base case
        if(ind>n) return false;
        if(ind==n) return true;
        if(dp[ind]!=-1) return dp[ind];
        
        
        for(int k=1;k<=nums[ind];k++)
        {
            if(helper(ind+k,n,nums,dp))
            {
                dp[ind]=1;
                return true;
            }
        }
        
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(0,n-1,nums,dp);
    }
};