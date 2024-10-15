//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* BST(int post[], int& idx, int lower, int upper){
    //Base condition
    if(idx <0 || post[idx] < lower || post[idx] > upper){
        return NULL;
    }
   // for post order (LRN) we will do NRL
    Node* root = new Node(post[idx--]);
    root->right = BST(post, idx, root->data, upper);
    root->left =  BST(post, idx, lower, root->data);
    return root; 
    
    
}
Node *constructTree (int post[], int size)
{
//code here
   int idx = size-1;
   return BST(post, idx, INT_MIN, INT_MAX); 
}