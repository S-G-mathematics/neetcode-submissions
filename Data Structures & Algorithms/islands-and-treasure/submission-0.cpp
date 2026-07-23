class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        
        int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(auto &d:directions){
            int nx=x+d[0];
            int ny=y+d[1];
            if(nx<0 || ny<0 || nx>=m ||ny>=n ||grid[nx][ny]==-1||vis[nx][ny]==1)continue;
            else{
                grid[nx][ny]=grid[x][y]+1;
                vis[nx][ny]=1;
                q.push({nx,ny});
            } 
        }
    }}
};
