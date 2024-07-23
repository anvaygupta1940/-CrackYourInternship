class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=0;
        int n=nums.size();
        for(int i=0;i<n;)
        {
            nums[ind++]=nums[i];
            i++;
            while(i<n && nums[i]==nums[i-1])i++;
        }
        return ind;
    }
};