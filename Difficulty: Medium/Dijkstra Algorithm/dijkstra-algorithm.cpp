// User Function Template
class Solution {
  public:
     
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<pair<int, int>> adj[V];
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            
        }
        
        vector<int> dist(V, INT_MAX);
        vector<bool> explored(V, 0);
        dist[src] = 0;  
        
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, src});
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            pq.pop();
            
            explored[node] = 1;
            
            for(auto nei: adj[node]){
                int fir = nei.first;
                int wei = nei.second;
                
                if(!explored[fir] && dist[fir] > dist[node] + wei){
                    dist[fir] = dist[node] + wei;
                    pq.push({dist[fir], fir});
                }
            }
            
        }
         
         
 
 // Solving without Priority Queue  Brute force        
        
        // int cnt = V;
        
        // while(cnt--){
            
        //     int node = -1, val = INT_MAX;
            
        //     for(int i=0; i<V; i++){
        //         if(explored[i] == 0 && dist[i] < val){
        //             node = i;
        //             val = dist[i];
        //         }
        //     }
        //     explored[node] = 1;
            
        //     for(auto nei: adj[node]){
        //         int fir = nei.first;
        //         int wei = nei.second;
                
        //         if(!explored[fir] && dist[fir] > dist[node] + wei){
        //             dist[fir] = dist[node] + wei;
        //         }
        //     }
        // }
        
        return dist;
        
    }
};