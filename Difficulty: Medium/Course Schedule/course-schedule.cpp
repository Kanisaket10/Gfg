class Solution {
  public:
    
    vector<int> isPossible(int N, int P, vector<vector<int>> prerequisites) {
        // Code here
        vector<int> adjList[N];
        vector<int> indeg(N);
    
        for(int i=0; i<P; i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<N; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i=0; i<adjList[node].size(); i++){
                indeg[adjList[node][i]]--;
                if(!indeg[adjList[node][i]]){
                    q.push(adjList[node][i]);
                }
            }
            
        }
        return ans;
    }

    
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        int p  = prerequisites.size();
        vector<int> res = isPossible(n, p, prerequisites);
        if(res.size() != n) res = {};
        
        return res;
        
    }
};