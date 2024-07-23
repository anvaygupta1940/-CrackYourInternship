class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<int>dR(m,0);
        vector<int>dC(n,0);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0){
                    dR[i]=1;
                    dC[j]=1;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dR[i] || dC[j]) matrix[i][j]=0;
            }
        }
        
        
    }
};