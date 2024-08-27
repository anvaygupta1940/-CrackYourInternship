class Solution {
public:
void helper(int ind, int n, string & curr, vector<string>& ans, int open, int close)
{
    // base case
    if(ind==2*n)
    {
        ans.push_back(curr);
        return ;
    }

    //placing opening bracket
    if(open>0)
    {
        curr+='(';
        helper(ind+1,n,curr,ans,open-1,close);
        curr.pop_back();
    }

    // placing closing bracket
    if(ind>0 && close>open)
    {
        curr+=')';
        helper(ind+1,n,curr,ans,open,close-1);
        curr.pop_back();
    }
    return ;
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr="";
        helper(0,n,curr,ans,n,n);
        return ans;
    }
};