//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detect_cycle(int node, vector<vector<int>>& adj, vector<int>& path, vector<int>& visited){
        visited[node] = 1;
        path[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            if(path[adj[node][i]]) return 1;
            if(!visited[adj[node][i]] && detect_cycle(adj[node][i], adj, path, visited)){
                return 1;
            }
        }
        path[node] = 0;
        return 0;
    }
    bool isCyclic(int v, vector<vector<int>> adj) {
        // code here
        //int v = adj.size();
        vector<int>path(v, 0);
        vector<int>visited(v,0);
        
        for(int i=0; i<v; i++){
            if(!visited[i] && detect_cycle(i, adj, path, visited)){
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends