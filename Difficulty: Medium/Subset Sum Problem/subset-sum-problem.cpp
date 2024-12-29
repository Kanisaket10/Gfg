//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
   // Recursion
    bool check(int idx, vector<int>& arr, int target){
        if(target == 0) return 1;
        if(idx == 0) return arr[0] == target;
        
        bool take = 0;
        if(target >= arr[idx]){
            take = check(idx-1, arr, target-arr[idx]);
        }
        bool not_take = check(idx-1, arr, target);
        
        return take | not_take;
    }
     
    // Memoization 
    bool check_memo(int idx, vector<int>&arr, int target, vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(idx == 0) return arr[0] == target;
        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool not_take = check_memo(idx-1, arr, target, dp);
        bool take = false;
        if(arr[idx] <= target){
            take = check_memo(idx-1, arr, target-arr[idx], dp);
        }
        return dp[idx][target]= take| not_take;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
       //return check(n-1, arr, target);
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return check_memo(n-1, arr, target, dp);
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends