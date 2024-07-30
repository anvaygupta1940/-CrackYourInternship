class Solution {
public:
void dfs(int i,int j, vector<vector<char>>& grid,int m,int n)
{
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0') return ;

    grid[i][j]='0';

    dfs(i-1,j,grid,m,n);
    dfs(i,j+1,grid,m,n);
    dfs(i+1,j,grid,m,n);
    dfs(i,j-1,grid,m,n);
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int cnt=0;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]=='1')
                {
                    dfs(row,col,grid,m,n);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};