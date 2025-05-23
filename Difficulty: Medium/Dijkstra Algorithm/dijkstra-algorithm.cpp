// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        //we have given edge list -> convert it to adj list
        vector<pair<int,int>>adj[V];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt= edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        //adj list is made
        
        //creating a priority queue -> min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,src});
        
        vector<int>dist(V,1e9);
        dist[src]=0;
        
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
            for(auto it: adj[node]){
                
                
                int vNode=it.first;
                int uDist=it.second;
                
                if(dist[vNode]>wt+uDist){
                    dist[vNode]=wt+uDist;
                    pq.push({dist[vNode],vNode});
                }
            }
        }
        
        return dist;
        
    }
};