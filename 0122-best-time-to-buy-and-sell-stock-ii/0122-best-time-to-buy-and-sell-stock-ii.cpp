class Solution {
public:
    int helper(int ind,bool buy, vector<int>& prices, int n, vector<vector<int>>& dp)
    {
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy){
            dp[ind][buy]=max(-prices[ind]+helper(ind+1,0,prices,n,dp),helper(ind+1,1,prices,n,dp));
        }else{
            dp[ind][buy]=max(prices[ind]+helper(ind+1,1,prices,n,dp),helper(ind+1,0,prices,n,dp));
        }
        
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(0,1,prices,n,dp);
    }
};