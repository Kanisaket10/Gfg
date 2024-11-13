//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        
        // vector<pair<int, pair<int, int>>> temp;
        
        // for(int i=0; i<K; i++){
        //     temp.push_back({arr[i][0],{i, 0}});
        // }
        
        // priority_queue
        
        
        
        
        
        
        vector<pair<int, pair<int, int>>> temp;
        
        for(int i=0; i<K; i++){
            temp.push_back({arr[i][0], {i,0}});
        }
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> p(temp.begin(), temp.end());
        
        vector<int> ans;
        pair<int, pair<int, int>> Element;
        int i, j;
        
        while(!p.empty()){
            Element = p.top();
            p.pop();
            ans.push_back(Element.first);
            i = Element.second.first;
            j = Element.second.second;
            if(j+1 <K){
                p.push({arr[i][j+1], {i, j+1}});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends