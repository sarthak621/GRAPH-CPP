//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,
             vector<pair<int,int>>& base,int row0, int col0){
                     int n=grid.size();
                     int m=grid[0].size();
                     
                     vis[row][col]=1;
                     base.push_back({row-row0,col-col0});
                     
                     int delRow[]={-1,0,+1,0};
                     int delCol[]={0,1,0,-1};
                     
                     for(int i=0;i<4;i++){
                         int nRow=row+delRow[i];
                         int nCol=col+delCol[i];
                         
                         if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 &&
                         !vis[nRow][nCol]){
                             dfs(nRow,nCol,grid,vis,base,row0,col0);
                         }
                     }
                     
                     
             }
             
             
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        //visited grid
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        
        //set-> used for find the distinct elements
        set<vector<pair<int, int>>> st;

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    //to store the base
                    vector<pair<int,int>>base;
                    
                    dfs(i,j,grid,vis,base,i,j);
                    st.insert(base);
                }
            }
        }
        return st.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends