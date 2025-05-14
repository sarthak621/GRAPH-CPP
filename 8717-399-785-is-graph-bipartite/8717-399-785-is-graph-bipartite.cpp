class Solution {
public:
    
    bool bfsCheck(int i, vector<int>&color,vector<vector<int>>& graph,int n ){
        queue<int>q;
        q.push(i);
        color[i]=0; //color the first node with the 0

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node]; //change the color from 0 to 1 or viceversa
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        //color array
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfsCheck(i,color,graph,n)==false){
                    return false;
                }
            }
        }
        return true;
    }
};