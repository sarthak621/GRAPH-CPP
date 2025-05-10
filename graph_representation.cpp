//GRAPH REPRESENTATION IN C++

//1. STORING A GRAPH IN FORM OF MATRIX {ADJACENCY MATRIX}  -> S.C=O(N X M)

#include <iostream>
using namespace std; 

int main() {
    
    //no, of nodes-> n and no. of edges->m
    int n,m;
    cin>>n>>m;
    
    //creating the adjacency matrix
    int adj[n+1][m+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u][v]=1;
        adj[v][u]=1;
    }
    return 0;
}


//2. STORING A GRAPH IN FORM OF LIST {ADJACENCY LIST} S.C=O(2E)

#include <iostream>
using namespace std; 

int main() {
    
    //no, of nodes-> n and no. of edges->m
    int n,m;
    cin>>n>>m;
    
    //creating the adjacency list
    vector<int>adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

// 3. IN CASE OF DIRECTED GRAPH     S.C=O(2E)

#include <iostream>
using namespace std; 

int main() {
    
    //no, of nodes-> n and no. of edges->m
    int n,m;
    cin>>n>>m;
    
    //creating the adjacency list
    vector<int>adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    return 0;
}


//4. STORING A WEIGHTED GRAPH IN FORM OF MATRIX {ADJACENCY MATRIX}  -> S.C=O(N X M)

#include <iostream>
using namespace std; 

int main() {
    
    //no, of nodes-> n and no. of edges->m
    int n,m;
    cin>>n>>m;
    
    //creating the adjacency matrix
    int adj[n+1][m+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

      int wt;
      cin>>wt;
        
        adj[u][v]=wt;
        adj[v][u]=wt;
    }
    return 0;
}
