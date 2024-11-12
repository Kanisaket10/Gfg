//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    
cout << "~" << "\n";
}
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  vector<pair<int, pair<int, int>>> temp;
  
  for(int i=0; i<n; i++){
      temp.push_back({mat[i][0],{i, 0}});
  }
  
  //MinHeap 
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());
  int ans;
  pair<int, pair<int, int>>Element;
  int i, j;
  
  while(k--){
      Element = p.top();
      p.pop();
      ans = Element.first;        // value
      i = Element.second.first;   // row
      j = Element.second.second;  // column
      
      if(j+1 < n){
          p.push({mat[i][j+1],{i,j+1}});
      }
  }
  return ans;
  
}
