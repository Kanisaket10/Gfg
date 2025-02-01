//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] =1;
        
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i] == parent) continue;
            if(visited[adj[node][i]]) return 1;
            if(dfs(adj[node][i], node, adj, visited)) return 1;
        }
        return 0;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        //bool ans =0;
        int v = adj.size();
        vector<bool> visited(v, 0);
        
        for(int i=0; i<v; i++){
            if(!visited[i] && dfs(i, -1, adj, visited)){
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends