// User function Template for C++

class Solution {
  public:
  
    int maxcapacity(int ind, int w, vector<int>& val, vector<int>& wt, vector<vector<int>>&dp ){
        if(w == 0) return 0;
        if(ind == 0){
            
            return (w/wt[0])*val[0];
        } 
        
        if(dp[ind][w] !=-1) return dp[ind][w];
        
        int notTake = maxcapacity(ind-1, w, val, wt, dp);
        int take =0;
        if(wt[ind] <= w){
            take = val[ind] + maxcapacity(ind, w-wt[ind], val, wt, dp);
            
        }
        return dp[ind][w] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n= wt.size();
        vector<vector<int>> dp(n, vector<int> (capacity+1, -1));
        
        return maxcapacity(n-1, capacity, val, wt, dp);
    }
};