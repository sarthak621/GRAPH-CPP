//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void dfs(int i,  vector<int> adj[],  int vis[],stack<int>& st,int V){
        vis[i]=1;
        // st.push(i);
        
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis,st,V);
            }
            
        }
        st.push(i);
    }
    
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
       for (auto &e : edges) {          // edges = {{u1,v1},{u2,v2},…}
           int u = e[0];
           int v = e[1];
           adj[u].push_back(v);         // store v as a neighbour of u
       }

        
        int vis[V]={0};
        vector<int>ans;
        
        stack<int>st;
        
        
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st,V);
            }
        }
        
        while(!st.empty()){
            int top=st.top();
            st.pop();
            ans.push_back(top);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
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