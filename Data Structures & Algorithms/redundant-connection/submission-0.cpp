class DSU{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x)
            return x;

        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){

        a=find(a);
        b=find(b);

        if(a==b)
            return;

        if(rank[a]<rank[b])
            swap(a,b);

        parent[b]=a;

        if(rank[a]==rank[b])
            rank[a]++;
    }

    bool connected(int a,int b){
        return find(a)==find(b);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();

        DSU dsu(n+1);

        for(auto &e:edges){

            int u=e[0];
            int v=e[1];

            if(dsu.connected(u,v))
                return e;

            dsu.unite(u,v);
        }

        return {};
    }
};