//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    // finding Longest prefix suffix 
        void findlps(vector<int>& lps, string s){
            int pre =0, suf =1;
            lps[0]=0;
            while(suf < s.size()){
                if(s[pre] == s[suf]){
                    pre++;
                    lps[suf] = pre;
                    suf++;
                }
                else{
                    if(pre == 0){
                        lps[suf]=0;
                        suf++;
                    }
                    pre = lps[pre-1];
                }
            }
        }
        
        vector <int> search(string pat, string txt)
        {
            //code here
            int  n= txt.size();
            int  m = pat.size();
            vector<int> ans;
            vector<int> lps(n,0);
            findlps(lps, pat);
            
            int first =0, second =0;
            
            while(first < n){  
                
                if(txt[first] == pat[second]){
                    first++;
                    second++;
                }
                if(second == m){
                    ans.push_back(first-second+1);
                    second = lps[second-1];
                }
                else if(txt[first] != pat[second]){
                    if(second ==0){
                        first++;
                    }
                    else{
                        second = lps[second-1];
                    }
                }
            }
            
            
           return ans;
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends