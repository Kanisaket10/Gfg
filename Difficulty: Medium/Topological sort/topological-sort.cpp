//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs_topo(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
        visited[node] =1;
        
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
              dfs_topo(adj[node][i], adj, visited, st);
            }  
        }
        st.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
         int v = adj.size();
    // Topological sort using dfs;
        
        // vector<int> ans;
        // vector<bool> visited(v, 0);
        
        // stack<int> st;
        
        // for(int i=0; i<v; i++){
        //     if(!visited[i]) {
        //         dfs_topo(i, adj, visited, st);
        //     }
        // }
        
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // return ans;
        
    // topological sort using bfs or kahn's algorithm
    
        vector<int> Indeg(v, 0);
        vector<int> ans;
        for(int i=0; i<v; i++){
            for(int j=0; j<adj[i].size(); j++){
                Indeg[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<v; i++){
            if(Indeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i=0; i<adj[node].size(); i++){
                Indeg[adj[node][i]]--;
                if(Indeg[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends