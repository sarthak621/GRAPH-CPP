class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        
        //given a adj list
        
        int n=adj.size();
        
        vector<int>dist(n,1e9);
        
        queue<pair<int,int>>q;
        
        dist[src]=0;
        
        q.push({src,0});
        
        while(!q.empty()){
            int node=q.front().first;
            // int duri=q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(dist[it]>dist[node]+1){
                    dist[it]=dist[node]+1;
                    q.push({it,dist[it]});
                }
            }
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(dist[i]!=1e9){
                ans.push_back(dist[i]);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};