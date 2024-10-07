//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// class Solution {
//   public:
      
//       int find(int in[], int InStart,int InEnd, int targ ){
         
//           for(int i=InStart; i<= InEnd; i++){
//               if(in[i] == targ)
//                 return i;
//           }
//           return -1;
//       }
      
//       Node* Tree(int in[], int post[], int InStart, int InEnd, int idx){
          
//           if(InStart > InEnd){
//               return NULL;
//           } 
          
//           Node* root = new Node(post[idx]);
          
//           // position of node in postorder array
//           int pos = find(in, InStart, InEnd, post[idx]);
          
        
//           root->right = Tree(in , post, pos+1, InEnd, idx-1);
//           root->left = Tree(in , post, InStart, pos-1, (idx-(InEnd -pos)-1));
          
//           return root;
//       }

//     // Function to return a tree created from postorder and inoreder traversals.
//     Node *buildTree(int n, int in[], int post[]) {
//         // Your code here
        
//       // idx of node in pre order array
//         int idx = n-1;
//         return Tree(in, post, 0, n-1, idx);
//     }
// };
class Solution {
  public:
    int find(int in[], int InStart, int InEnd, int targ) {
        for (int i = InStart; i <= InEnd; i++) {
            if (in[i] == targ)
                return i;
        }
        return -1;
    }

    Node* Tree(int in[], int post[], int InStart, int InEnd, int& idx) {
        // Base case
        if (InStart > InEnd) {
            return NULL;
        }

        // Create a new node with the current postorder value
        Node* root = new Node(post[idx]);
        idx--;  // Move to the previous node in postorder

        // If this is a leaf node (no children), just return it
        if (InStart == InEnd) {
            return root;
        }

        // Find the position of this node in the inorder array
        int pos = find(in, InStart, InEnd, root->data);

        // Recurse for right and left subtrees
        // First, we build the right subtree because we are processing postorder
        root->right = Tree(in, post, pos + 1, InEnd, idx);
        root->left = Tree(in, post, InStart, pos - 1, idx);

        return root;
    }

    // Function to return a tree created from postorder and inorder traversals.
    Node* buildTree(int n, int in[], int post[]) {
        int idx = n - 1;  // Initialize the index to the last element of postorder
        return Tree(in, post, 0, n - 1, idx);
    }
};



//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends