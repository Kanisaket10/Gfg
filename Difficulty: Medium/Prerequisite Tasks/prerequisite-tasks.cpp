class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> adjList[N];
        vector<int> indeg(N);
    
        for(int i=0; i<P; i++){
            adjList[prerequisites[i].second].push_back(prerequisites[i].first);
            indeg[prerequisites[i].first]++;
        }
        
        queue<int> q;
        for(int i=0; i<N; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        int ans =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans++;
            
            for(int i=0; i<adjList[node].size(); i++){
                indeg[adjList[node][i]]--;
                if(!indeg[adjList[node][i]]){
                    q.push(adjList[node][i]);
                }
            }
            
        }
        return (ans == N)? 1: 0; 
    }
};