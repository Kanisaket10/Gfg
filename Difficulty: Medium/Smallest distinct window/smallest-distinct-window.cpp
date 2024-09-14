//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        vector<bool> check(256,0);
        int first =0, second=0;
        int len=str.size();
        int diff =0;
        
        // finding the unique characters 
        for(int i=0; i<str.size(); i++){
            if(check[str[i]]==0){
                diff++;
                check[str[i]] =1;
            }
                
        }
        
        vector<int> count(256,0);
        while(second < str.size()){
            
            while(diff && second < str.size()){
            
                if(count[str[second]] == 0){
                    diff--;
                }
                count[str[second]]++;
                second++;
            
            }
            len = min(len, second-first);
            
            while(diff !=1){
                len = min(len, second-first);
                count[str[first]]--;
                
                if(count[str[first]]==0)  diff++;
                first++;
            }
           
        }
        
        return len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends