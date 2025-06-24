// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        //now declare the priority queue
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;


        pq.push({0,0}); // {dist,node}

        //dist array and ways array
        vector<long long >dist(n,1e18);
        vector<int>ways(n,0);

        dist[0]=0;
        ways[0]=1;

        int mod= int (1e9+7);

        while(!pq.empty()){
            auto ele=pq.top();
            int distNode=ele.first;
            int node=ele.second;

            pq.pop();

            if (distNode > dist[node]) continue; // ✅ Important line


            for(auto it:adj[node]){
                //now we have to take road adj nodes.
                int adjNode=it.first;
                int edgeWt=it.second;
                
                long long newDist=distNode+ 1LL*edgeWt;

                if(newDist<dist[adjNode]){
                    //distance and ways both updated
                    dist[adjNode]=newDist;
                    ways[adjNode]=ways[node]; 
                    pq.push({newDist,adjNode});
                }

                else if(newDist==dist[adjNode]){
                    //Ways updated only
                    ways[adjNode]=(ways[node]+ways[adjNode]) % mod; 
                }
            }

        }

        return (ways[n-1])%mod;

    }
};