class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        vector<int>indg(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                indg[i]++;
            }
        }
        
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(indg[i]==0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node])
            {
                indg[it]--;
                if(indg[it]==0)
                {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};