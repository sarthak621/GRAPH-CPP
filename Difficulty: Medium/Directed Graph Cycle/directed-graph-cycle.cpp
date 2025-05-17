//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //finding directed graph using bfs using kahn's algo 
        //converting the list into adjacency list
            vector<int>adj[V+1];
            for(int i=0;i<edges.size();i++){
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);
            }
            
            //making the indegree array and filling it
            vector<int>indegree(V,0);
            
            for(int i=0;i<V;i++){
                for(auto it:adj[i]){
                    indegree[it]++;
                }
            }
            vector<int>topo; //for storing the ans
            queue<int>q;
            
            for(int i=0;i<V;i++){
                if(indegree[i]==0){
                    q.push(i);
                    
                }
            }
            
            while(!q.empty()){
                int node=q.front();
                q.pop();
                topo.push_back(node);
                
                for(auto it: adj[node]){
                    indegree[it]--;
                    
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
       if(topo.size()==V) return false;
    
        return true;  
    }
};





// finding directed graph using dfs

    // class Solution {
//   public:
  
//     bool dfs(int node,int V, vector<vector<int>> &adj,vector<int> &vis,vector<int> &pathVis){
//         vis[node]=1;
//         pathVis[node]=1;
        
//         for(auto it: adj[node]){
//             if(!vis[it]){
//                 if(dfs(it,V,adj,vis,pathVis)==true){
//                     return true;
//                 }
//             }
//             else if(pathVis[it]){
//                     return true;
//                 }
//         }
        
//         pathVis[node]=0;
//         return false;
//     }
    
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         // Step 1: Convert edge list to adjacency list
//         vector<vector<int>> adj(V);
//         for(auto &e : edges){
//             adj[e[0]].push_back(e[1]);
//         }

//         // Step 2: Use DFS to detect cycle
//         //visited array
//         vector<int>vis(V,0);
//         // path visited
//         vector<int>pathVis(V,0);
        
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                 if(dfs(i,V,adj,vis,pathVis)==true){
//                     return true;
//                 }
//             }
//         }
//         return false;
        
//     }
// };


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends