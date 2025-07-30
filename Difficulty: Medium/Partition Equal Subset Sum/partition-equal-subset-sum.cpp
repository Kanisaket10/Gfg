class Solution {
  public:
    
    bool check_Subset(int ind, vector<int>& nums, int t, vector<vector<int>>& dp){
        
        if(t == 0) return 1;
        if(ind == 0) return nums[0]==t;
        
        if(dp[ind][t] != -1) return dp[ind][t];
        if(nums[ind] <= t)
            return dp[ind][t] = check_Subset(ind-1, nums, t-nums[ind], dp) || check_Subset(ind-1, nums, t, dp);
        return dp[ind][t] = check_Subset(ind-1, nums, t, dp);
    }
    
    bool equalPartition(vector<int>& arr) {
        // code here
        int n =arr.size();
        int total =0;
        for(int i=0; i<n; i++) total += arr[i];
        
        if(total % 2 !=0) return 0;
        int t = total/2;
        
        vector<vector<int>> dp(n, vector<int>(t+1, -1));
        
        return check_Subset(n-1, arr, t, dp);
        
    }
};