//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    //vector<int> dp(m+1, -1);
    long long int fac(int n, vector<long long int >& dp){
        // Base
        if(n<=1) return n;
        
        if(dp[n] !=-1){
           return dp[n];
        }
        
      return dp[n] = (fac(n-1, dp) + fac(n-2, dp)) %1000000007; 
    }
    long long int topDown(int n) {
        // code here
        if(n<=1) return n;
        vector<long long int> dp(n+1, -1);
        return fac(n, dp);
       
    }
    long long int bottomUp(int n) {
        // code here
        if(n <= 1) return n;
        
        long long int prev = 0;
        long long int curr = 1;
        long long int res;
        
        for(int i=2; i<=n; i++){
             res = (curr + prev) % 1000000007; // 1 2 3 5 8
             prev = curr;                      // 1 1 2 3
             curr = res;                        // 1 2 3 5
        }
       return res % 1000000007; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends