class Solution {
public:
bool canFill(int row, int col, vector<vector<char>>& board , char ch)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==ch) return false;
        if(board[i][col]==ch) return false;
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==ch) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            // empty space
            if(board[i][j]=='.')
            {
                for(char ch='1';ch<='9';ch++)
                {
                    if(canFill(i,j,board,ch)==true)
                    {
                        board[i][j]=ch;
                        if(solve(board)==true) return true;
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};