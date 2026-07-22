class Solution {
private:
vector<vector<int>> grid;
vector<vector<bool>> vis;
int r,c;
public:
    int dfs(int x,int y){
        if(x<0 || y<0 || x>=r || y>=c || grid[x][y]==0) return 1;
        if(vis[x][y])return 0;
        vis[x][y]=1;
        return dfs(x-1,y)+dfs(x+1,y)+dfs(x,y-1)+dfs(x,y+1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid=grid;
        r=grid.size();
        c=grid[0].size();
        vis=vector<vector<bool>>(r,vector<bool>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return dfs(i,j);
                }
            }
        }
        return 0;
    }
};