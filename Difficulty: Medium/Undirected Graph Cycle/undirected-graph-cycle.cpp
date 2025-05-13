//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool detect(int src,int vis[],vector<vector<int>>& edges){
        vis[src]=1;
        
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it: edges[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                
                //if parent is visited and next of node is alreay visited
                else if(parent!=it){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
      // Step 1: Build adjacency list
      
      // Step 1: Build adjacency list
        vector<vector<int>> adjList(V);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); // Because the graph is undirected
        }
        
        //  vector<vector<int>> adjList(V);

        // for(int i=0;i<V;i++){
        //     for(int j=0;j<V;j++){
        //         if(edges[i][j] && i!=j){
        //             adjList[i].push_back(j);
        //             adjList[j].push_back(i);
        //         }
        //     }
        // }
        
        
        
        int vis[V]={0};
        
        //for connected components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,vis,adjList)) return true;
            }
        }
        return false;
    }
};


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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends