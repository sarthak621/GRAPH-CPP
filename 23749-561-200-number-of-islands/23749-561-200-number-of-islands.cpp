class Solution {
public:

    void bfs(int row,int col, vector<vector<int>>&vis,vector<vector<char>>& grid){
        int n=grid.size(); //row
        int m=grid[0].size(); //col
        
        //visit karo
        vis[row][col]=1;

        //queue me dalo
        queue<pair<int,int>>q;

        q.push({row,col});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;

            q.pop();

            //You may assume all four edges of the grid are all surrounded by water.
            int dRow[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
            int dCol[] = {0, 1, 0, -1};

            for(int i=0;i<4;i++){
              
                    int nRow=row+dRow[i];
                    int nCol=col+dCol[i];

                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
                       grid[nRow][nCol]=='1' && !vis[nRow][nCol]){
                        vis[nRow][nCol]=1;
                        q.push({nRow,nCol});
                       }

                
            }


        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); //row
        int m=grid[0].size(); //col

        int count=0;

        vector<vector<int>>vis(n,vector<int>(m,0)); //visited array of nXm filled with 0
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]!=1){
                    //then visit karo , count ko update karo , bfs tarversal karo
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }

        return count;
    }
};