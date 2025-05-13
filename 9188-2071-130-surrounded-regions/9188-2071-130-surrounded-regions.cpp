class Solution {
public:

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis){\
        int n=board.size();
        int m=board[0].size();

        vis[row][col]=1;
        
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && board[nRow][nCol]=='O' && !vis[nRow][nCol]){
                dfs(nRow,nCol,board,vis);
            }

        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        //sabhi boundaries wale 0 ko visit kar lo

        //traverse the 0 in first row and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis);
            }

            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis);
            }
        }

        //traverse the 0 in first col and last col
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }

            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
            }
        }


        //ab jo andar wale hai or not visited hai usko X mark kar do
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

   

    }
};