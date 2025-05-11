class Solution {
public:

    void dfs(int node,vector<vector<int>> &adjList, vector<int>&vis){
        vis[node]=1;

        for(auto it: adjList[node]){
            if(!vis[it]){
                dfs(it,adjList,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // we have to find the no. of provinces

        // firstly we have given a adjacency matrix we have to convert it in adj. list

        //no. of nodes
        int n= isConnected.size();
        
        // adj list
        vector<vector<int>> adjList(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        //now make visited array of size n
        vector<int>vis(n,0);
        int count=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjList,vis);
            }
        }
        
        return count;
    }
};