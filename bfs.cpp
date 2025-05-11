//bfs traversal T.C=> O(N)+O(2E) and S.C=> O(3N)

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
   //make visited array
   vector<int>vis(n,0);

   vis[0]=1;

   queue<int>q;
   q.push(0);

   vector<int>bfs;

   while(!q.empty()){
       int front=q.front();
       q.pop();

       //bfs me dal do
       bfs.push_back(front);

       //ab uske adjacent element ko visited array me true mark karo or queue me daal do
       for(auto it: adj[front]){
           if(!vis[it]){
               vis[it]=1;
               q.push(it);
           }
       }
   }
   return bfs;


}




