//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>num(1,1);
        
        while(N>1){
            int sum =0;
            int carry=0;
            for(int i=0; i<num.size(); i++){
                sum = num[i]*N + carry;
                num[i] = sum%10;
                carry = sum/10;
                
            }
            while(carry){
                num.push_back(carry%10);
                carry/=10;
            }
            
            N--;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends