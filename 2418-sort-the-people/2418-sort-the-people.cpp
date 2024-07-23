class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>ds;
        int n=names.size();
        if(n==1) return names;

        for(int i=0;i<n;i++)
        {
            ds.push_back({heights[i],names[i]});
        }

        sort(ds.begin(),ds.end());

        vector<string>ans;
        for(int i=n-1;i>=0;i--)
        {
            ans.push_back(ds[i].second);
        }

        return ans;
    }
};