class Solution {
  public:
   
    bool checkSubsetSum(int n, vector<int>& nums, int sum){
        if(n==0 && sum==0) return 1;
        if(sum == 0) return 1;
        if(n<0 || sum < 0) return 0;
        return checkSubsetSum(n-1, nums, sum-nums[n]) || checkSubsetSum(n-1, nums, sum);
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        return checkSubsetSum(n-1, arr, sum);
        
    }
};