
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int maxprofit=0;
        int minsofar=prices[0];
        for(int i=1;i<n;i++)
        {
            minsofar=min(minsofar,prices[i]);
            int profit=prices[i]-minsofar;
            maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
        
    }
};