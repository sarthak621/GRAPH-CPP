// leetcode 1091. Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.




class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //given the grid
        // now lets draw the dist[][] matrix 

        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));

        // queue in the form of {dist,{row,col}}
        queue<pair<int,pair<int,int>>>q;

        //now declare the src and destination
        pair<int,int>src(0,0);
        pair<int,int>dest(n-1,m-1);
        
        dist[src.first][src.second]=0;
        // since it has mentioned that length of a clear path is the number of visited cells of this path.
        q.push({1,{src.first,src.second}});

        // //for traversing in the all 4 direction of row and col
        // int dr[]={-1,0,1,0};
        // int dc[]={0,1,0,-1};

        //for traversing in the all 8 direction of row and col
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        //base case
        if(grid[0][0]!=0) return -1; 

        //base case in case of single elememt
        if(n==1 && m==1) return 1;


        //logic
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int distance=it.first;
            int drow=it.second.first;
            int dcol=it.second.second;

            for(int i=0;i<8;i++){
                int newRow=dr[i]+drow;
                int newCol=dc[i]+dcol;

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m &&
                    grid[newRow][newCol]==0 && distance+1< dist[newRow][newCol]){
                        //update the distance matrix
                        dist[newRow][newCol]=distance+1;
                        if(newRow==dest.first && newCol==dest.second){
                            return dist[newRow][newCol];
                        }

                        q.push({distance+1,{newRow,newCol}});
                    }
            }

        }
        return -1;
    }
};
