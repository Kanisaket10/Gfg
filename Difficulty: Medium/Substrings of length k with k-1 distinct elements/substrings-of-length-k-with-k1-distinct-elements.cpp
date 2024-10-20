//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        // code here
        unordered_map<char,int>mp;
        int count=0;
        for(int i=0;i<k;i++){
            mp[s[i]]++;
        }
        if(mp.size()==k-1){
            count++;
        }
        for(int i=k;i<s.size();i++){
            if(!mp.empty() && mp[s[i-k]]>1){
                mp[s[i-k]]--;
            }
            else{
                mp.erase(s[i-k]);
            }
            mp[s[i]]++;
            if(mp.size()==k-1){
            count++;
            }
        }
    
    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends