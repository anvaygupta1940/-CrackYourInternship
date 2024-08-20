class Solution {
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
public:
    void dfs(int row,int col,vector<vector<int>>& vis,queue<pair<int,pair<int,int>>>&q, vector<vector<int>>& grid,int n)
    {
        q.push({0,{row,col}});
        vis[row][col]=1;
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,q,grid,n);
            }
        }
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        bool found=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    found=true;
                    dfs(i,j,vis,q,grid,n);
                    break;
                }
            }
            if(found) break;
        }
        
        while(!q.empty())
        {
            int dst=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n)
                {
                    if(!vis[nrow][ncol] && grid[nrow][ncol]==1) return dst;
                    else if(!vis[nrow][ncol] && grid[nrow][ncol]==0)
                    {
                        vis[nrow][ncol]=1;
                        q.push({dst+1,{nrow,ncol}});
                    }
                }
            }
        }
        
        return -1;
        
        
    }
};