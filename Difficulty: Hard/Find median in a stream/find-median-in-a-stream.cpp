//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    priority_queue<int> leftmaxheap;
    priority_queue<int, vector<int>, greater<int>> rightminheap;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(leftmaxheap.empty()){
            leftmaxheap.push(x);
            return;
        }
        
        if(x > leftmaxheap.top()){
            rightminheap.push(x);
        }
        else {leftmaxheap.push(x);}
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(rightminheap.size()> leftmaxheap.size()){
            leftmaxheap.push(rightminheap.top());
            rightminheap.pop();
        }
        else{
            if(rightminheap.size() < leftmaxheap.size()-1){
                rightminheap.push(leftmaxheap.top());
                leftmaxheap.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(leftmaxheap.size() > rightminheap.size()){
            return leftmaxheap.top();
        }
        else{
            double ans = leftmaxheap.top()+ rightminheap.top();
            return ans/2;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends