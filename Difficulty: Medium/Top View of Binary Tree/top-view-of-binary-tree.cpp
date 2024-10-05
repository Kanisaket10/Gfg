//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void find_pos(Node *root, int pos, int& l, int& r ){
        if(!root) return;
        
        l = min(pos, l);
        r = max(pos, r);
        find_pos(root->left, pos-1, l, r);
        find_pos(root->right, pos+1, l, r);
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        if(!root) return {};
        int l=0, r =0;
        
        // finding the postion of left most and right most node
        find_pos(root,0,l, r);
        int n = r-l+1;
        
        vector<int> ans(n);
        vector<bool> filled(n);
        queue<Node*> q;
        queue<int> q_idx;
        
        q.push(root);
        q_idx.push(-1*l);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            int pos = q_idx.front();
            q_idx.pop();
            
            if(!filled[pos]){
              filled[pos] = 1;
              ans[pos] = temp->data;
            }
            
            if(temp->left) {
                q.push(temp->left);
                q_idx.push(pos-1);
            }
            if(temp->right){
                q.push(temp->right);
                q_idx.push(pos+1);   
            }
        }
        return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends