// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        
        //assign i==j as 0 else 1e9 in an adj matrix
        int n=dist.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // if(i!=j) dist[i][j]=1e8;  //// already set  {is set to a large value (i.e., 108) to represent infinity.}
                if(i==j) dist[i][j]=0;
            }
        }
        
        //logic
        
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via]<1e8 && dist[via][j]<1e8){
                       dist[i][j]=min(dist[i][j], dist[i][via]+dist[via][j]);
                    }
                    
                }
            }
        }
        

        
        //detect -ve cycle -> not present in this ques
        
    }
};