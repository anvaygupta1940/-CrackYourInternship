class Solution {
public:
void f(int curr, int n , int k, vector<int>& comb, vector<vector<int>>& ans)
{
    // base condition
    if(k==0)
    {
        ans.push_back(comb);
        return;
    }
    else if(curr>n) return;
    
    // take
    comb.push_back(curr);
    f(curr+1,n,k-1,comb,ans);
    // non -take
    comb.pop_back();
    f(curr+1,n,k,comb,ans);
    return ;
}
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> ans;
        f(1,n,k,comb,ans);
        return ans;
    }
};