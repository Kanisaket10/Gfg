class Solution {

  public:
  
    int check_subset(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
        if(target == 0) return 1;
        if(ind ==0) return arr[0] == target;
        
        if(dp[ind][target]!= -1) return dp[ind][target];
        
        if(arr[ind] <= target){
            return dp[ind][target] = check_subset(ind-1, target-arr[ind], arr, dp) || check_subset(ind -1, target, arr, dp);
        }
        return dp[ind][target] = check_subset(ind -1, target, arr, dp);
    }
    
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int Range = 0;
        
        for(int i=0; i<n; i++) Range += arr[i];
        vector<vector<int>> dp(n, vector<int>((Range/2)+1, -1));
        
        // for (int i = 0; i <= Range; i++) {
        //   check_subset(n - 1, i, arr, dp);
        // }
        
        int mn =INT_MAX;
        for(int s1=0; s1<=Range/2; s1++){
            if(check_subset(n - 1, s1, arr, dp) == 1){
                mn = min(mn, abs(Range - (2*s1)));
            }
            
        //   if (dp[n-1][s1] == 1){
        //       if(mn > abs(Range - (2*s1)))
        //           mn = abs(Range - (2*s1));
        //   }
        }
    
        return mn;
        
    }
};
