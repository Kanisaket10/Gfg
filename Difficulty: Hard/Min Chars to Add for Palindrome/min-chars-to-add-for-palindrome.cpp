//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        string rev = str;
        int size = str.size();
        reverse(rev.begin(), rev.end());
        
        str +="$";   // abc$
        str +=rev;    // abc$cba
        int n = str.size();
        //finding LPS
        vector<int> lps(n, 0);
        int pre = 0, suf = 1; 
        while(suf < str.size()){
            if(str[pre] == str[suf]){
                pre++;
                lps[suf] = pre;
                suf++;
            }
            else{
                if(pre == 0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre= lps[pre-1];
                }
            }
        }
        return size - lps[n-1];
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends