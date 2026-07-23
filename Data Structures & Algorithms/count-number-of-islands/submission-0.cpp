class Solution {
private:
vector<vector<char>> grid;
vector<vector<bool>> vis;
int r,c;
public:
    void bfs(int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto &d:directions){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx<0 || ny<0 ||nx>=r || ny>=c || grid[nx][ny]=='0' ||vis[nx][ny]==1)continue;
                else if(grid[nx][ny]=='1'){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
                else continue;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
    this->grid=grid;
    r=grid.size();
    c=grid[0].size();
    int ans=0;
    vis=vector<vector<bool>>(r,vector<bool>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]=='1' && vis[i][j]==0){
            bfs(i,j);
            ans++;
            }
        }
    }
    return ans;
    }
};
