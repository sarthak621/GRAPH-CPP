// leetcode 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance


// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        //dist matrix
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        
        //convert the edges to the matrix   // bidirectional 
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }

        //if i==j then 0
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(i==j) dist[i][j]=0;
          }
        }

        //logic of floyd warshall
         for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via]<1e9 && dist[via][j]<1e9){
                       dist[i][j]=min(dist[i][j], dist[i][via]+dist[via][j]);
                    }
                    
                }
            }
        }

        //now we have to compute the threshold distance with each cities

        int cntCity=n;
        int cityNo=-1;

        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(dist[city][adjCity]<=distanceThreshold){
                    cnt++;
                }
            }

            if(cnt <= cntCity){
                cntCity=cnt;
                cityNo=city;
            }
        }

        return cityNo;

    }
};
