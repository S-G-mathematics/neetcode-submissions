class Solution {
private:
int r,c;
vector<vector<int>> grid;
vector<vector<bool>> vis;
public:
    int bfs(int i,int j){
        int area=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        area++;
        int directions[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto& d:directions){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx<0 || ny<0 || nx>=r ||ny>=c || grid[nx][ny]==0 ||vis[nx][ny]==1)continue;
                else{
                    area++;
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid=grid;
        r=grid.size();
        c=grid[0].size();
        vis=vector<vector<bool>>(r,vector<bool>(c,0));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int temp=bfs(i,j);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};
