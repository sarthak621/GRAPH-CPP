// leetcode 1631. Path With Minimum Effort


// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        //base case-->> in case of single element
        if(n==1 && m==1) return 0;

        //making a priority queue -->>> {diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        //making the dist matrix
        vector<vector<int>>dist(n,vector<int>(m,1e9));

        //fill the dist[0][0] as 0

        pq.push({0,{0,0}});

        //traversing in 4 directions
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;

             // In Dijkstra's algorithm, the first time you pop the destination node from the min-heap, you've reached it with the minimum effort.
            if(row==n-1 && col==m-1) return dist[row][col];

            //loop
            for(int i=0;i<4;i++){
                int dRow=dr[i]+row;
                int dCol=dc[i]+col;

                if(dRow>=0 && dRow<n && dCol>=0 && dCol<m){
                    int effort=max(abs(heights[dRow][dCol]-heights[row][col]),diff);

                    //agar effort jyada hai current distance matrix me check kar ke toh upadate karo
                    if(effort<dist[dRow][dCol]){
                        dist[dRow][dCol]=effort;
                        pq.push({dist[dRow][dCol],{dRow,dCol}});
                    }
                }
            }

        }
        return 0;


    }
};
