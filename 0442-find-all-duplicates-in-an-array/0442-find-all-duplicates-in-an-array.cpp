class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        set<int>st;
        for(auto it:nums)
        {
            if(st.find(it)==st.end()) st.insert(it);
            else ans.push_back(it);
        }

        return ans;
    }
};