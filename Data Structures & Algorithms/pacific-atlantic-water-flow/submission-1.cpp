class Solution {
public:

    void bfs(queue<pair<int,int>> &q,
             vector<vector<bool>> &vis,
             vector<vector<int>> &heights){

        int r = heights.size();
        int c = heights[0].size();

        int dir[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()){

            auto [x,y] = q.front();
            q.pop();

            for(auto &d : dir){

                int nx = x + d[0];
                int ny = y + d[1];

                if(nx < 0 || ny < 0 || nx >= r || ny >= c)
                    continue;

                if(vis[nx][ny])
                    continue;

                // Reverse flow
                if(heights[nx][ny] < heights[x][y])
                    continue;

                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int r = heights.size();
        int c = heights[0].size();

        vector<vector<bool>> pac(r,vector<bool>(c,false));
        vector<vector<bool>> atl(r,vector<bool>(c,false));

        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;

        // Left & Right borders
        for(int i=0;i<r;i++){

            pq.push({i,0});
            pac[i][0]=true;

            aq.push({i,c-1});
            atl[i][c-1]=true;
        }

        // Top & Bottom borders
        for(int j=0;j<c;j++){

            if(!pac[0][j]){
                pq.push({0,j});
                pac[0][j]=true;
            }

            if(!atl[r-1][j]){
                aq.push({r-1,j});
                atl[r-1][j]=true;
            }
        }

        bfs(pq,pac,heights);
        bfs(aq,atl,heights);

        vector<vector<int>> ans;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};