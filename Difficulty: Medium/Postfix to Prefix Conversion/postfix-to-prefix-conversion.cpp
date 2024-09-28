//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        int n = s.size();  
        stack<string> st;
        int i=0; 
        string temp;
        
        while(i<n){
            if(s[i] == '^' || s[i] == '*' || s[i] == '/' || s[i]== '+' || s[i] == '-'){
                string top2 = st.top(); //C
                st.pop();
                string top1 = st.top(); //B
                st.pop();
                st.push(s[i]+top1+top2);  // /BC
            }
            else{
                temp = s[i];
                st.push(temp);  //ABC
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
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends