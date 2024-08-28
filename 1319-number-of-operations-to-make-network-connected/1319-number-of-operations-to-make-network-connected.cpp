class Disjoint{
    public:
    vector<int>par,size;
    Disjoint(int n)
    {
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) par[i]=i;
    }

    int findULP(int node)
    {
        if(par[node]==node) return node;
        return par[node]=findULP(par[node]);
    }

    void UnionBySize(int u,int v)
    {
        int ulp_u=findULP(u);
        int ulp_v=findULP(v);

        if(ulp_u==ulp_v) return ;
        else if(size[ulp_u]<size[ulp_v])
        {
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra=0;
        Disjoint d(n);

        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];

            if(d.findULP(u)==d.findULP(v)) extra++;
            else{
                d.UnionBySize(u,v);
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(d.par[i]==i) cnt++;
        }

        if(extra>=(cnt-1)) return cnt-1;
        return -1;
    }
};