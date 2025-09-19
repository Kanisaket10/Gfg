// User function Template for C++

class Solution {
  public:
     int dir[4] = {-1, 0, 0, 1};
     int dic[4] = {0, -1, 1, 0};
     
     bool valid(int i, int j, int n, int m){
         return i>=0 && i<n && j>=0 && j<m;
     }
     
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(X==0 && Y ==0) return 0;
        if(A[0][0] == 0) return -1;
        
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0,{0, 0}});
        A[0][0] = 0;
    
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second.first;
            int step = q.front().second.second;
            q.pop();
            
            if(i == X && j == Y) {
                return step;
            }
            for(int d = 0; d<4; d++){
                int r = i + dir[d];
                int c = j + dic[d];
                
                if(valid(r, c, N, M) && A[r][c] == 1){
                
                    A[r][c] = 0;
                    q.push({r,{c, step+1}});
                    
                }
                
            }
        }
        
        return -1;
    }
};