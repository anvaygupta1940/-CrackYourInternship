#include<bits/stdc++.h>
class Solution {
public:
    // int f(int ind,int prev_ind,vector<int>&nums,int n,vector<vector<int>>& dp)
    // {
    //     // base case
    //     if(ind==n) return 0;
    //     if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    //     int take=0;
    //     if(prev_ind==-1 ||nums[ind]>nums[prev_ind]) take=1+f(ind+1,ind,nums,n,dp);
    //     int nontake=f(ind+1,prev_ind,nums,n,dp);
    //     return dp[ind][prev_ind+1]=max(take,nontake);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        //vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // vector<int>next(n+1,0),curr(n+1,0);
        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        //     {
        //         int nontake=next[prev_ind+1];
        //         int take=0;
        //         if(prev_ind==-1 || nums[ind]>nums[prev_ind])
        //         {
        //             take=1+next[ind+1];
        //         }
        //         curr[prev_ind+1]=max(take,nontake);
        //     }
        //     next=curr;
        // }
        // return next[-1+1];
        // //return f(0,-1,nums,n,dp);
        // vector<int>dp(n,1);
        // int maxi=1;
        // for(int ind=0;ind<n;ind++)
        // {
        //     for(int prev_ind=0;prev_ind<ind;prev_ind++)
        //     {
        //         if(nums[ind]>nums[prev_ind])
        //         {
        //             dp[ind]=max(dp[ind],1+dp[prev_ind]);
        //         }
        //     }
        //     maxi=max(maxi,dp[ind]);
        // }
        // return maxi;
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
            {
                len++;
                temp.push_back(nums[i]);
            }
            else 
            {
                auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
                *it=nums[i];
            }
        }
        return len;
    }
};