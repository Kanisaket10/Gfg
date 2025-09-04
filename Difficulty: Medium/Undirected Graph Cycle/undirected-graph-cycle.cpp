class Solution {
  public:
    bool dfs(int node, int parent, vector<bool>& visited, vector<int> adjList[]){
        visited[node] = 1;
        
        for(int j=0; j<adjList[node].size(); j++){
            if(adjList[node][j] == parent) continue;
            if(visited[adjList[node][j]] == 1) return 1;
            if(dfs(adjList[node][j], node, visited, adjList)) return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int E = edges.size();
        vector<int> adjList[V];
        
        for(int i=0; i<E; i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
            
        }
        vector<bool> visited(V, 0);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && dfs(i,-1, visited, adjList)){
                return 1;
            }
        }
        return 0;
        
    }
};