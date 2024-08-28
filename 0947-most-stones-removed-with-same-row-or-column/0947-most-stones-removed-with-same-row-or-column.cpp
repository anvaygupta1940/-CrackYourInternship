class Solution {
public:
    int n;

    // Helper function to perform DFS and mark connected stones as visited.
    void dfs(int i, vector<int> &vis, vector<vector<int>>& stones) {
        vis[i] = 1; // Mark the current stone as visited
        for (int j = 0; j < n; j++) {
            // If the stone is not visited and shares the same row or column
            if (!vis[j]) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    dfs(j, vis, stones); // Recursively visit connected stones
                }
            }
        }
    }

    // Main function to calculate the maximum number of stones that can be removed.
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size(); // Number of stones
        vector<int> vis(n, 0); // Visited array to keep track of visited stones
        int ans = 0; // Number of connected components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) { // If the stone is not visited
                dfs(i, vis, stones); // Perform DFS to mark all connected stones
                ans++; // Increment the number of connected components
            }
        }
        return n - ans; // Maximum number of stones that can be removed
    }
};