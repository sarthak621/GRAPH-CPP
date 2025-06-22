// 787. Cheapest Flights Within K Stops

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //creating up the adj graph
        // vector<pair<int,int>>adj[n];
        vector<vector<pair<int, int>>> adj(n);

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        //distance array
        vector<int>dist(n,1e9);
        dist[src]=0;

        //queue => {stop,node,dist}
        queue<pair<int,pair<int,int>>>q;

        q.push({0,{src,0}});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int distance=it.second.second;

            if(stop>k) continue;
            //Skip just this iteration (this invalid path)
            //  But keep processing other possible paths in the queue.

            for(auto iter:adj[node]){
                int adjNode=iter.first;
                int edgeWt=iter.second;

                if(dist[adjNode]>edgeWt+distance && stop<=k){
                    dist[adjNode]=edgeWt+distance;
                    q.push({stop+1,{adjNode,dist[adjNode]}});
                }

            }

        }

        if(dist[dst]==1e9) return -1;

        return dist[dst];



    }
};

