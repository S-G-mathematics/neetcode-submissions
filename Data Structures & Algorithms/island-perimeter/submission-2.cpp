class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,0));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    int p=0;
                    int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();
                        for(auto &d:dir){
                            int nx=x+d[0];
                            int ny=y+d[1];
                            if(nx<0||ny<0||nx>=r||ny>=c||grid[nx][ny]==0)p++;
                            else if(!vis[nx][ny]){
                                vis[nx][ny]=1;
                                q.push({nx,ny});
                            }
                        }

                    }
                return p;
                }
            }
        }
        return 0;
    }
};