class Solution {
  public:
    void DFS(int node, vector<bool>& visited,vector<int> adj[]){
        visited[node] = 1;
        
        for(int nei: adj[node]){
            if(!visited[nei]){
                DFS(nei, visited, adj);
            }
        }
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        
        // Eular Circuit
        // Degree should even
        // graph should be connected  
        
        // Eular Path
        // only zero or Two node can have odd deg and remaining should have even deg
        // graph should be connected
        
        int odd = 0;
        vector<int> deg(V, 0);
        for(int i=0; i<V; i++){
            deg[i] = adj[i].size();
            if(deg[i]%2) odd++;
            
        }
        
        if(odd != 0 && odd != 2) return 0;
        
        vector<bool> visited(V, 0);
        
        for(int i=0; i<V; i++){
            if(deg[i]){
                DFS(i, visited, adj);
                break;
            }
            
        }
        
        for(int i=0; i<V; i++){
            if(deg[i] && !visited[i]) return 0;
        }
        
        return (odd == 0)? 2 : 1; 
        
    }
};