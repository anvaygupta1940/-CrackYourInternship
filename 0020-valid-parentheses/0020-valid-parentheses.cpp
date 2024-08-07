class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ch:s)
        {
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else{
                if(st.empty()) return false;
                
                if(abs(ch-st.top())==1 || abs(ch-st.top())==2) st.pop();
                else return false;
            }
        }
        
        return st.size()==0;
    }
};