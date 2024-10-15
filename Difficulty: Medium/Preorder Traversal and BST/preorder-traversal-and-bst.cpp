//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Node{
    public:
  int data;
  Node *left, *right;
  
  Node(int val){
      data = val;
      left = right = NULL;
  }
  
};


class Solution {
  public:
    Node* BST(int arr[], int& idx, int lower, int upper, int N){
        if(idx == N || arr[idx] <lower ||arr[idx] >upper){
            return NULL;
        }
        
        Node* root = new Node(arr[idx++]);
        root->left = BST(arr, idx, lower, root->data, N);
        root->right = BST(arr, idx, root->data, upper, N);
        return root;
    } 
    int canRepresentBST(int arr[], int N) {
        // code here
        int idx =0;
        Node *temp = BST(arr, idx, INT_MIN, INT_MAX,N);
        if(idx >= N) return 1;
        return 0; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends