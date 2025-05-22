// User function Template for C++
class Solution {
  public:
  
    void topoSort(int i,vector<pair<int,int>>adj[],int n,stack<int>&st,vector<int>&vis){
        vis[i]=1;
        
        for(auto it:adj[i]){
            int v=it.first;
            if(!vis[v]){
                topoSort(v,adj,n,st,vis);
            }
        }
        
        st.push(i);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        //V->vertices E->edges
        
        //we have to convert the edge list into adj list
        int n=V;
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt= edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        //adjacency list is created 
        
        // step 1: do a topo sort 
        stack<int>st;
        vector<int>vis(n,0);
        
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoSort(i,adj,n,st,vis);
            }
        }
        
        //step 2: takes node out of stack and relax the edges
        
        vector<int>dist(n,1e9);
        dist[0]=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            for(auto it: adj[node]){
                int v=it.first;
                int wt=it.second;
                
                if(dist[v]>wt+dist[node]){
                    dist[v]=wt+dist[node];
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
