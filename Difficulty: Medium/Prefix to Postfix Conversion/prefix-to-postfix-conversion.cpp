//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        
        // prefix to postfix
        string s = pre_exp;
        int n= s.size();
        int i=n-1;
        string temp;
        stack<string> st;
        
        while(i>=0){
            if(s[i] == '^' || s[i] == '/' || s[i] == '*'|| s[i] == '+' || s[i]=='-'){
                string top1 = st.top();  // A
                st.pop();
                string top2 = st.top();   // K
                st.pop();
                st.push(top1+top2+s[i]);
                
            }else{
                temp = s[i];
                st.push(temp);
            }
            i--;
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends