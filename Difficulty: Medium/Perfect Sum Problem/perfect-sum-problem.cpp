class Solution {
  public:
    int Count_subset(int ind, int target, vector<int>& arr ,  vector<vector<int>>& dp){
    if(ind == 0) {
        if(target == 0) return 1+(target == arr[ind]);
        return arr[ind] == target;
    }
    
    if(dp[ind][target]!=-1) return dp[ind][target];
    
    if(arr[ind] <= target){
        return dp[ind][target] = Count_subset(ind-1, target-arr[ind], arr, dp)+ Count_subset(ind-1, target, arr, dp);
    } 
     return dp[ind][target] = Count_subset(ind -1, target, arr, dp);  
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return Count_subset(n-1, target, arr, dp);
        
    }
};