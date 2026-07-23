class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int fresh=0;
        int t=0;
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)fresh++;
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty() && fresh>0){
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto&d:directions){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(nx<0 || ny<0 ||nx>=r||ny>=c)continue;
                    if(grid[nx][ny]!=1)continue;
                    grid[nx][ny]=2;
                    fresh--;
                    q.push({nx,ny});
                }
                
            }
            t++;
        }
        if(fresh!=0){
            return -1;
        }else{
            return t;
        }
    }
};
