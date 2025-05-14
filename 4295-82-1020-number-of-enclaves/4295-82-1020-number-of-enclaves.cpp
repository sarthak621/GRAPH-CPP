class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();

        vis[row][col]=1;

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 && !vis[nRow][nCol]){
                dfs(nRow,nCol,grid,vis);
            }

        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        // if boundary 1 hai toh mark those guy as visited

        //checking for 1 in first row and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,grid,vis);
            }

             if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,grid,vis);
            }
        }


        //checking for 1 in fisrt col and last col.
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis);
            }

            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,grid,vis);
            }
        }
        int count=0;
        //ab jo andar wale hai or not visited hai usko X mark kar do
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
       
       return count;

    }
};