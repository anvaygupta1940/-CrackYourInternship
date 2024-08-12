class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        
        vector<int>left(n); // left[i] is the distance b/w arr[i] and previous smaller element
        vector<int>right(n); // right[i] is the distance b/w arr[i] and its next smaller element
        
        stack<int>st;
        
        st.push(0);
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            
            if(st.empty()) left[i]=i+1;
            else left[i]=i-st.top();
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        st.push(n-1);
        right[n-1]=1;
        
        for(int i=n-2;i>=0;i--)
        {
            
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            
            if(st.empty()) right[i]=n-i;
            else right[i]=st.top()-i;
            
            st.push(i);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            long long prod=(left[i]*right[i])%mod;
            prod=(prod*arr[i])%mod;
            ans=(ans+prod)%mod;
        }
        
        return ans%mod;;
    }
};