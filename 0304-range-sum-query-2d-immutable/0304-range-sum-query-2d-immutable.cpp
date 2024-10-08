class NumMatrix {
private:
    vector<vector<int>> A;
    int m, n;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        A.resize(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                A[i][j] = matrix[i-1][j-1] + A[i-1][j] + A[i][j-1] - A[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return A[row2+1][col2+1] - A[row1][col2+1] - A[row2+1][col1] + A[row1][col1];
    }
};
