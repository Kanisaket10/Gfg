//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
//   Memoization
    int count(int ind, int n, vector<int>&price, vector<vector<int>>& dp){
        if(ind == 0) return n * price[ind];
        if(dp[ind][n] != -1) dp[ind][n];
        
        int not_take = 0 + count(ind -1, n, price, dp);
        int take = INT_MIN;
        int rodlength = ind +1;
        if(rodlength <= n) take = price[ind] + count(ind, n-rodlength, price, dp);
        return dp[ind][n] = max(take, not_take);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return count(n-1, n, price, dp);
        
        // Tabulation
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int T=0; T<=n; T++) dp[0][T] = T* price[0];
        
        for(int i=1; i<n; i++){
            for(int T =0; T <= n; T++){
                int not_take = dp[i-1][T];
               
                int take = INT_MIN;
                int rodlength = i +1;
                if(rodlength <= T) take = price[i] + dp[i][T- rodlength];
                dp[i][T] = max(not_take, take);
                
            }
        }
       return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends