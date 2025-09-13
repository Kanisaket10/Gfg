class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
           vector<bool> visited(n, 0);
           vector<int> dist(n, -1);
           
           queue<int> q;
           q.push(src);
           
           visited[src] = 1;
           dist[src] = 0;
           
           while(!q.empty()){
               int node = q.front();
               q.pop();
               
               for(int nei : adj[node]){
                   if(!visited[nei]){
                       visited[nei] = 1;
                       dist[nei] = 1 + dist[node];
                       q.push(nei);
                   }
               }
           }
        return dist;
    }
};