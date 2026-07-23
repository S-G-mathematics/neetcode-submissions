class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        queue<pair<int,int>> q;
        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<r;i++){
            if(board[i][0]=='O')q.push({i,0});
            if(board[i][c-1]=='O')q.push({i,c-1});
        }
        for(int i=0;i<c;i++){
            if(board[0][i]=='O')q.push({0,i});
            if(board[r-1][i]=='O')q.push({r-1,i});
        }

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            board[x][y]='T';
            for(auto &d:dir){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>0 && ny>0 && nx<r && ny<c && board[nx][ny]=='O'){
                    board[nx][ny]='T';
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='T')board[i][j]='O';
            }
        }
    }
};
