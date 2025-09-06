class Solution {
  public:
    void bfs(int n, vector<int> adj[], vector<int>& indeg, string& ans, vector<bool>& exists){
       
        queue<int> q;
        for(int i=0; i<n; i++){
            if( exists[i] && !indeg[i]) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            ans += node + 'a';
            q.pop();
            
            for(auto nei : adj[node]){
                indeg[nei]--;
                if(indeg[nei] == 0) q.push(nei);
            }
            // for(int i=0; i<adj[node].size(); i++){
            //     indeg[adj[node][i]]--;
            //     if(indeg[adj[node][i]] == 0){
            //         q.push(adj[node][i]);
            //     }
            // }
        }
        
    }
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        
        vector<bool> exists(26, false);
        
        for(int i=0; i<n; i++){
            for(auto ch : words[i]){
                exists[ch - 'a'] = true;
            }
        }
        
        vector<int> adjList[26];
        vector<int> indeg(26, 0);
        
        for(int i=0; i<n-1; i++){
            string s1 = words[i], s2 = words[i+1];
            int j=0, k=0;
            
            while(j < s1.size() && k < s2.size() && s1[j] == s2[k]){
                    j++;
                    k++;
            }
            
            if(j == s1.size()) continue;
            if(k == s2.size()) return ""; 
            
            adjList[s1[j] - 'a'].push_back(s2[k]- 'a');
            indeg[s2[k] - 'a']++;
        }
        
        string ans = "";
         
        bfs(26, adjList, indeg, ans, exists);
        
        for(int i=0; i<26; i++) if(indeg[i] != 0) return "";
        
        return ans;
    }
};