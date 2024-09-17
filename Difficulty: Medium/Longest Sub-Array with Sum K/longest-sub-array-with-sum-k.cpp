//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        // Complete the function
         map<long long, int> preSumMap;
         long long sum =0;
         int maxLen=0;
         
         for(int i=0; i<n; i++){
             //prefix
             sum += A[i];
             
             if(sum == k){
                 maxLen = max(maxLen, i+1);
             }
             
             long long rem = sum-k;
             
             if(preSumMap.find(rem) != preSumMap.end()){
                 int len = i - preSumMap[rem];
                  maxLen = max(maxLen, len);
             }
             
             if(preSumMap.find(sum) == preSumMap.end()){
                 preSumMap[sum] = i;
             }
         }
        
        
        return maxLen;
        
        
        
        
// For positive Integers only
        
        // int left =0, right =0;
        // long long sum =A[0];
        // int maxLen =0;
        
        // while(right < n){
        //     if(left <= right && sum > k){
        //         sum -= A[left];
        //         left++;
        //     }
            
        //     if(sum == k){
        //         maxLen = max(maxLen, right-left+1);
        //     }
        //     right++;
        //     if(right < n) sum +=A[right];
            
        // }
        // return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends