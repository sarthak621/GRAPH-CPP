// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) return 0;

        queue<pair<int,int>>q;
        q.push({0,start});  // {steps,node}
        
        //now make the distance array
        vector<int>dist(100000,1e9);
        dist[start]=0;
        
        int mod=100000;
        
        while(!q.empty()){
            auto top=q.front();
            int step=top.first;
            int node=top.second;
            
            q.pop();
            
            for(auto it:arr){
                int num=(it*node)%mod;
                if(step+1<dist[num]){
                    dist[num]=step+1;
                    q.push({dist[num],num});
                    if(num==end) return dist[num];
                }
            }
            
        }
        return -1;
    }
};
