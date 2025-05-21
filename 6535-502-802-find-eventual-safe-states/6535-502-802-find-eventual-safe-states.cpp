class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adjRev(n);

        // int indegree[n]={0};
        vector<int>indegree(n,0);
        
        // step 1 :changes the edges 
        for(int i=0;i<n;i++){
            // i ke nbr honge it 
            // hame reverse karna hai 
            for(auto it: graph[i]){
                adjRev[it].push_back(i);  // [1,2] => 1->2 {indegree of 1 is 0} and then i=1 and it=2   {adjRev[it].push_back(i);} => [2,1]=> 2->1 and {indegree of 1 is now 1}
                indegree[i]++;
            }
        }

        //step 2 -> get all the nodes with indegree 0 and push it in the queue 
        queue<int>q;
        vector<int>safeNodes;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it:adjRev[node]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        sort(safeNodes.begin(),safeNodes.end());
        
        return safeNodes;

    }
};