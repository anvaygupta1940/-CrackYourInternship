class Solution {
public:
void uniqueSubsets(int ind,int n, vector<int>&nums,vector<int>&ds, vector<vector<int>>& ans)
{
    ans.push_back(ds);

    for(int i=ind;i<n;i++)
    {
        if(i>ind && nums[i]==nums[i-1]) continue;

        ds.push_back(nums[i]);
        uniqueSubsets(i+1,n,nums,ds,ans);
        ds.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        uniqueSubsets(0,n,nums,ds,ans);
        return ans;
    }
};