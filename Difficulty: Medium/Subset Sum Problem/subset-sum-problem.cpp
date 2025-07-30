class Solution {
  public:
   
   // RECURSIVE CODE
    bool checkSubsetSum(int n, vector<int>& nums, int sum){
        if(n==0 && sum==0) return 1;
        if(sum == 0) return 1;
        if(n<0 || sum < 0) return 0;
        return checkSubsetSum(n-1, nums, sum-nums[n]) || checkSubsetSum(n-1, nums, sum);
        
    }
    
    // MEMOIZATION
    bool checkSubsetSum_dp(int n, vector<int>& nums, int sum, vector<vector<int>>& dp){
        if(sum==0) return 1;
        if(n == 0) return nums[n] == sum;
      
        if(dp[n][sum]!=-1) return dp[n][sum];
        return dp[n][sum] = checkSubsetSum_dp(n-1, nums, sum-nums[n], dp) || checkSubsetSum_dp(n-1, nums, sum, dp);
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        //return checkSubsetSum(n-1, arr, sum);
        
        // vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        // return checkSubsetSum_dp(n-1, arr, sum, dp);
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        if(arr[0] <= sum) dp[0][arr[0]] = 1;
        
        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
               bool take =0;
                if(arr[i] <=j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take || dp[i-1][j];
            }
        }
        
       return dp[n-1][sum]; 
        
    }
};