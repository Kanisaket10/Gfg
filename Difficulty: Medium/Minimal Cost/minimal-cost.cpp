//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   int jump(int idx, vector<int>& arr, vector<int>&dp, int k){
//       if(idx == 0) return 0;
       
//       if(dp[idx]!= -1) return dp[idx];
//       int minstep = INT_MAX;
//       for(int i=1; i<=k; i++){
//           int jumpcost = INT_MAX;
//           if(idx-i >=0){
//               jumpcost = jump(idx-i,arr, dp, k)+ abs(arr[idx]+arr[idx-i]);
//               minstep = min(minstep, jumpcost);
//           }
//       }
//       return dp[idx] = minstep;
//   }
     int solve(vector<int>& height, int n, int k, vector<int> &dp) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int ans = INT_MAX;
        for(int j = 1; j <= k; j++) {
            int jumpStep = INT_MAX;
            if(n - j >= 0) jumpStep = solve(height, n - j, k, dp) + abs(height[n] - height[n - j]);
            
            ans = min(ans, jumpStep);
        }
        dp[n] = ans;
        return dp[n];
    }
  
    int minimizeCost(int k, vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
       return solve(height,n-1, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends