class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
         vector<pair<int, int>> adj[n+1];
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            
        }
        
        vector<int> parent(n+1,-1);
        vector<int> dist(n+1, INT_MAX);
        vector<bool> explored(n+1, 0);
        dist[1] = 0;  
        
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, 1});
        
         while(!pq.empty()){
            
            int node = pq.top().second;
            pq.pop();
            
            explored[node] = 1;
            
            for(auto nei: adj[node]){
                int ind = nei.first;
                int wei = nei.second;
                
                if(!explored[ind] && dist[ind] > dist[node] + wei){
                    dist[ind] = dist[node] + wei;
                    parent[ind] = node;
                    pq.push({dist[ind], ind});
                }
            }
            
        }
        
        vector<int> ans;
        int temp = n;
       // ans.push_back(n);
        if (parent[n] == -1) return {-1};
        
        while(temp != -1){
            ans.push_back(temp);
            temp = parent[temp];
        }
        
        ans.push_back(dist[n]);
        reverse(ans.begin(), ans.end());
        
        return ans;
        
        
       
    }
};