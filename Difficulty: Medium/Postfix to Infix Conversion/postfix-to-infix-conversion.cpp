//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string s) {
        // Write your code here
        int n = s.size(), i=0;
        string temp = "";
        
        stack<string> st;
        
        while(i<n){
            // if(st.size() <2){
            //     st.push(s[i]);
            // }
            if(s[i] == '^' ||s[i] =='*' || s[i]=='/' || s[i] == '+'|| s[i]=='-') 
            {
                 string top2 = st.top();
                 st.pop();
                 string top1 = st.top();
                 st.pop();
            
               st.push('('+ top1+s[i]+top2+')');
            }
            else{
                temp = s[i];
                st.push(temp);
            }
            i++;
        }
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends