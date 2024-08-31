class Solution {
public:
    pair<int,int> kavya(string s){
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')a++;
            else b++;
        }
        return {a,b};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        vector<vector<int>>kav(k,vector<int>(2,0));
        int tol0=0,tol1=0;
        for(int i=0;i<k;i++){
            pair<int,int>a=kavya(strs[i]);
            kav[i][0]=a.first;
            kav[i][1]=a.second;  
        }
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int z=0;z<kav.size();z++){
            int temp0=kav[z][0];
            int temp1=kav[z][1];
            for(int i=m;i>=temp0;i--){
                for(int j=n;j>=temp1;j--){
                    dp[i][j]=max(dp[i][j],1+dp[i-temp0][j-temp1]);
                }
            }
        }
        return dp[m][n];
    }
};