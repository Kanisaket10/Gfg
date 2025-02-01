//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node, vector<int> adj[], vector<bool>& visited){
        visited[node]=1;
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                visited[adj[node][i]] =1;
                dfs(adj[node][i], adj, visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        // int v = adj.size();
        vector<int> adjList[v];
        
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(adj[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(v, 0);
        int cnt =0;
        
        for(int i=0; i<v; i++){
            if(!visited[i]){
                dfs(i, adjList, visited);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends