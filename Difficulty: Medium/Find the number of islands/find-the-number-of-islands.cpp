//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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

            for(int delRow=-1;delRow<=1;delRow++){
                for(int delCol=-1;delCol<=1;delCol++){
                    int nRow=delRow+row;
                    int nCol=delCol+col;

                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
                       grid[nRow][nCol]=='L' && !vis[nRow][nCol]){
                        vis[nRow][nCol]=1;
                        q.push({nRow,nCol});
                       }

                }
            }


        }

        //conencted 1's ko mark karo visited
    }
    
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
         int n=grid.size(); //row
        int m=grid[0].size(); //col

        int count=0;

        vector<vector<int>>vis(n,vector<int>(m,0)); //visited array of nXm filled with 0
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && vis[i][j]!=1){
                    //then visit karo , count ko update karo , bfs tarversal karo
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }

        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends