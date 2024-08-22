class Solution {
public:
bool isPalindrome(string& s , int start, int end)
{
    while(start<=end)
    {
        if(s[start]!=s[end]) return false;
        start++,end--;
    }
    return true;
}
void allPart(int ind, string & s, vector<vector<string>>& res, vector<string>& part)
{
    if(ind==s.size())
    {
        res.push_back(part);
        return ;
    }

    for(int i=ind;i<s.size();i++)
    {
        if(isPalindrome(s,ind,i)){
            part.push_back(s.substr(ind,i-ind+1));
            allPart(i+1,s,res,part);
            part.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        allPart(0,s,res,part);
        return res;
    }
};